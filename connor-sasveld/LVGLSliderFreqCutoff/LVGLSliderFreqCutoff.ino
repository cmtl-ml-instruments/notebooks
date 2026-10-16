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
#include "ES8331.h"

// --- Verified Freenove ESP32-S3 Physical Hardware Pins ---
#define TFT_CS       10   // Chip Select
#define TFT_DC       46   // Data/Command pin
#define TFT_RST      -1   // Tied to system power reset line
#define LCD_BL_PIN   45   // Screen Backlight illumination power line
#define TOUCH_CS     21   // Freenove touch chip pin
#define TOUCH_IRQ    36   // Touch interrupt pin

// I2S Pins for FNK0104 Touch Screen
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

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
FT6336U ts(I2C_SDA, I2C_SCL, RST, INT);
ES8311 es8311;
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

    data->point.x = map(y, 0, SCREEN_HEIGHT + 20, 0, SCREEN_WIDTH);
    data->point.x = constrain(data->point.x, 0, 319);
    data->point.y = map(x, SCREEN_WIDTH, 0, 0, SCREEN_HEIGHT);

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
float currentFilterCutoff = 2000.0f; 
float currentVelocity = 0.8f;        
bool synthPlaying = false;

// Convert MIDI Note to Base Frequency in Hz
float midiToFreq(int note) {
  return 440.0f * powf(2.0f, (note - 69.0f) / 12.0f);
}

void updateSynthSound(int note, float filterCutoff, float velocity) {
  float baseFreq = midiToFreq(note);

  // Restored character array buffer size brackets
  char msg[96];
  snprintf(msg, sizeof(msg), "v0w0f%.1fF%.0fa0.85l%.2f", baseFreq, filterCutoff, velocity);
  amy_add_message(msg);
  synthPlaying = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
  amy_config.features.startup_bleep = 1;
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
  
  // Start with default note
  updateSynthSound(scaleNotes[activeNoteIndex], currentFilterCutoff, 0.8f);
}

void loop() {
  lv_timer_handler();

  static unsigned long lastNoteChangeTime = 0;
  if (millis() - lastNoteChangeTime > 1500) {
    lastNoteChangeTime = millis();
    
    activeNoteIndex = (activeNoteIndex + 1) % totalScaleNotes; 
    
    updateSynthSound(scaleNotes[activeNoteIndex], currentFilterCutoff, 0.8f);
    Serial.printf("[PURE SOFTWARE] Active Scale Degree: %s (%0.1f Hz)\n", noteNames[activeNoteIndex], midiToFreq(scaleNotes[activeNoteIndex]));
  }

  delay(5);
}
