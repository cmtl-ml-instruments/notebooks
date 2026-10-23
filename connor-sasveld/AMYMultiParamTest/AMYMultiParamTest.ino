//Test UI for 2.8inch Touchscreen Freenove ESP32
//A basic UI just testing out the baility to use a touch screen an and LVGL library
//I coded the infrastructure for AMY to run and the UI to run but haven't yet connected them. That is my main action item for this next week

#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <FT6336U.h>
#include <lvgl.h>
#include "src/ui/ui.h"
#include <SPI.h>
#include <AMY-Arduino.h>
#include <ES8311.h>
#include "src/ui/vars.h"

// --- Verified Freenove ESP32-S3 Physical Hardware Pins ---
#define TFT_CS       10   // Chip Select
#define TFT_DC       46   // Data/Command pin
#define TFT_RST      -1   // Tied to system power reset line
#define LCD_BL_PIN   45   // Screen Backlight illumination power line
#define TOUCH_CS     21   // Freenove touch chip pin
#define TOUCH_IRQ    36   // Touch interrupt pin

// I2C Pins for FNK0104 Touch Screen (shared with ES8311 codec)
#define I2C_SDA      16
#define I2C_SCL      15
#define RST          18
#define INT          17

// Audio Codec Pins
#define I2S_MCK      4
#define I2S_BCK      5
#define I2S_WS       7
#define I2S_DOUT     8

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

enum ParamId {
  P_CUTOFF,
  P_RESONANCE,
  NUM_PARAMS
};

struct Param {
  int osc;              //Which oscillator in the synth's voice
  const char* amyCode;  //AMY's letter for this parameter
  int32_t value;         //Current slider value
  float scale;          //AMY recieves value / scale
  const char* labelf;   //How label is formatted (how it displays the value / scale)
};

Param params[] = {
  {0, "F",  2000, 1.0f,   "%.0f Hz"  },
  {0, "R",  7,    10.0f,  "%.1f"     },
};

static_assert(sizeof(params) / sizeof(params[0]) == NUM_PARAMS,
  "params table and ParamId enum are out of sync");

char labelBufs[NUM_PARAMS][24];   // one 24-character text buffer per parameter

void sendParam(int id) {
  const Param& p = params[id];
  char msg[32];
  snprintf(msg, sizeof(msg), "i1v%d%s%.3f", p.osc, p.amyCode, p.value / p.scale);
  amy_add_message(msg);
}

void sendAllParams() {
  for (int i = 0; i < NUM_PARAMS; i++) sendParam(i);
}

#define EEZ_PARAM(name, id)                                                 \
  int32_t get_var_##name() { return params[id].value; }                     \
  void set_var_##name(int32_t v) { params[id].value = v; sendParam(id); }

#define EEZ_LABEL(name, id)                                  \
  const char* get_var_##name() {                             \
    snprintf(labelBufs[id], sizeof(labelBufs[id]),           \
             params[id].labelf,                              \
             params[id].value / params[id].scale);           \
    return labelBufs[id];                                    \
  }

extern "C" {
  EEZ_PARAM(cutoff_value,     P_CUTOFF)
  EEZ_PARAM(resonance_value,  P_RESONANCE)

  EEZ_LABEL(cutoff_label_value,     P_CUTOFF)
  EEZ_LABEL(resonance_label_value,  P_RESONANCE)
}

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
FT6336U ts(I2C_SDA, I2C_SCL, RST, INT);
bool codecReady = false;

void my_display_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) { //LVGL needs a screen flush function to work
  uint32_t w = (area->x2 - area->x1 + 1); //uint32_t is used to do safetly sized math
    //x1 is left edge of the screen, x2 is right edge of the screen, the difference between them is the width
      //same is the case with y1 and y2
    //the -> operator is like the . operator but with directly editing memory locations in C++

  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.writePixels((uint16_t*)color_p, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp_drv);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  FT6336U_TouchPointType touch_data = ts.scan();

  if (touch_data.touch_count > 0) {
    int16_t x = touch_data.tp[0].x;
    int16_t y = touch_data.tp[0].y;

    data->point.x = y;                          // chip y (0-319) runs along the screen's width
    data->point.x = constrain(data->point.x, 0, SCREEN_WIDTH - 1);
    data->point.y = (SCREEN_HEIGHT - 1) - x;    // chip x (0-239) runs the opposite way along the height
    data->point.y = constrain(data->point.y, 0, SCREEN_HEIGHT - 1);

    data->state = LV_INDEV_STATE_PR; //Pressed
  } else {
    data->state = LV_INDEV_STATE_REL; //Released
  }
}

// --- Scale Definition (C Major / Pentatonic 2-Octave Span) ---
const int scaleNotes[] = { 
  48, 50, 52, 53, 55, 57, 59,  // C3, D3, E3, F3, G3, A3, B3
  60, 62, 64, 65, 67, 69, 71,  // C4, D4, E4, F4, G4, A4, B4
  72, 74, 76, 77, 79, 81, 83,  // C5, D5, E5, F5, G5, A5, B5
  84                           // C6
};
const char* noteNames[] = {
  "C3", "D3", "E3", "F3", "G3", "A3", "B3",
  "C4", "D4", "E4", "F4", "G4", "A4", "B4",
  "C5", "D5", "E5", "F5", "G5", "A5", "B5",
  "C6"
};
const int totalScaleNotes = sizeof(scaleNotes) / sizeof(scaleNotes[0]);

// Dynamic Instrument State
int activeNoteIndex = 7;     //default center note: C4 (index 7)
int octaveShift = 0;              
bool synthPlaying = false;

// Convert MIDI Note to Base Frequency in Hz
float midiToFreq(int note) {
  return 440.0f * powf(2.0f, (note - 69.0f) / 12.0f);
}

void updateSynthSound(int note) {
  // float baseFreq = midiToFreq(note);

  // Restored character array buffer size brackets
  char msg[96];
  snprintf(msg, sizeof(msg), "i1n%dl0.5", note);
  amy_add_message(msg);
  synthPlaying = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTxTimeoutMs(0); //Makes it so the computer never waits to read Serial output
  delay(1000);
  Wire.begin(16, 15, 400000); //(SDA, SCL)

  pinMode(LCD_BL_PIN, OUTPUT);
  digitalWrite(LCD_BL_PIN, HIGH);

  tft.begin();
  tft.setRotation(1);
  ts.begin();

  lv_init();

  //Create buffer structure
  static lv_disp_draw_buf_t draw_buf;
  static lv_color_t buf1[SCREEN_WIDTH * 10];
  lv_disp_draw_buf_init(&draw_buf, buf1, NULL, SCREEN_WIDTH * 10);

  //Create and initialize the display driver registration structure
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  //Assign resolution boundaries
  disp_drv.hor_res = SCREEN_WIDTH;
  disp_drv.ver_res = SCREEN_HEIGHT;

  //Link the flush callback and draw buffer
  disp_drv.flush_cb = my_display_flush;
  disp_drv.draw_buf = &draw_buf;

  //Register the driver inside LVGL
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();

  // 3. ES8311 Codec Init
  if (es8311.begin(Wire, I2C_SDA, I2C_SCL, 400000)) {
    codecReady = true;
    es8311.setVolume(88); // 88% volume
    Serial.println("[OK] ES8311 Audio Codec ready at 44.1 kHz");
  } else {
    Serial.println("[WARN] ES8311 Codec not responding; will continue synthesis.");
  }

  // 6. AMY Synth Engine Init
  amy_config_t amy_config = amy_default_config();
  // amy_config.features.startup_bleep = 1;
  amy_config.features.default_synths = 0;
  amy_config.platform.multithread = 1;
  amy_config.platform.multicore = 1;
  amy_config.audio = AMY_AUDIO_IS_I2S;

  amy_config.i2s_mclk = I2S_MCK;
  amy_config.i2s_bclk = I2S_BCK;
  amy_config.i2s_lrc  = I2S_WS;
  amy_config.i2s_dout = I2S_DOUT;
  amy_config.i2s_din  = -1;

  amy_start(amy_config);
  Serial.println("[OK] AMY Engine running!");
  amy_add_message("i1iv1K128");
  amy_add_message("i1v0G1");
  sendAllParams();
  delay(10);
  
  // Start with default note
  updateSynthSound(scaleNotes[activeNoteIndex]);
}

void loop() {
  lv_timer_handler();
  ui_tick();

  static unsigned long lastNoteChangeTime = 0;
  if (millis() - lastNoteChangeTime > 1500) {
    lastNoteChangeTime = millis();
    
    activeNoteIndex = (activeNoteIndex + 1) % totalScaleNotes; 

    Serial.println(params[P_CUTOFF].value);

    updateSynthSound(scaleNotes[activeNoteIndex]);
    Serial.printf("[PURE SOFTWARE] Active Scale Degree: %s (%0.1f Hz)\n", noteNames[activeNoteIndex], midiToFreq(scaleNotes[activeNoteIndex]));
  }

  delay(5);
}