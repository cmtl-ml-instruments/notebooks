# Week 4 — AMY Synthesizer Bring-Up & IMU Gestural Scale Control

*Copy this into a new file in your folder and fill it in. Plain sentences under the headings are fine — you do not need to know any formatting.*

**Name:** Mohan  
**Credit hours:** 2
**Date:** October 2, 2026  

---

## Goals

What you set out to do this week:
- Bring up the AMY (Additive Music Synthesizer) sound engine on the ESP32-S3 microcontroller to output clean audio via I2S.
- Initialize and configure the onboard Everest Semi ES8311 audio codec and hardware power amplifier.
- Interface the 6-DoF LSM6DSOX IMU (accelerometer and gyroscope) to the synthesis engine.
- Implement real-time signal filtering (Exponential Moving Average) to eliminate hand tremors and mechanical shock.
- Map continuous linear tilt and rotational movements to musical parameters: roll to scale degree selection across a 2-octave musical scale, pitch tilt to octave shifts and low-pass filter sweeps, and gyro rate to acoustic vibrato and dynamics.
- Build an interactive real-time visual monitor on the LCD screen.

## Methods

What you actually did. Link everything you used — papers, videos, repositories, documentation, parts. If you used an AI assistant at any point, say so and say what you asked it. That is information, not a confession:
- **Repositories & Libraries:**
  - [AMY Synthesizer by Shorepine (Brian Whitman & Dan Ellis)](https://github.com/shorepine/amy): Fixed-point polyphonic synthesizer library running dual-core FreeRTOS tasks with hardware I2S DMA streaming at 44.1 kHz.
  - [Adafruit LSM6DS Library](https://github.com/adafruit/Adafruit_LSM6DS) & [Adafruit Unified Sensor](https://github.com/adafruit/Adafruit_Sensor).
  - [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) for graphics primitives.
- **Software Implementation:**
  - Created a custom C++ driver class that initializes the codec registers over I2C at 44.1 kHz, configures the internal clock divider for an 11.2896 MHz master clock (MCLK on GPIO 17, BCLK on GPIO 18, WS on GPIO 21, DOUT on GPIO 15), sets the DAC volume to 88%, unmutes the DAC, and drives the PA enable pin LOW.
  - Designed an Exponential Moving Average low-pass filter running on the 104 Hz IMU data stream to filter out muscle tremors and mechanical bounce.
  - Implemented continuous gestural mapping: mapped roll angles to a 22-note musical scale (`C3` to `C6`), forward/backward pitch tilt to octave shifts and resonant filter sweeps ($350\text{ Hz} \to 4500\text{ Hz}$), and gyroscope rotational energy to subtle pitch vibrato.
  - Rendered a real-time LCD dashboard featuring an active note banner, live frequency counter, animated keyboard ribbon highlighting the active key in cyan, and visual bar gauges for roll, pitch, and gyro rates.
- **AI Assistant Usage:**
  - Used Antigravity (Gemini 3.8 Flash) to inspect board schematics, identify I2S/I2C pin conflicts and codec power enable logic, integrate and compile the AMY synthesizer library with dual-core FreeRTOS I2S DMA on ESP32-S3, diagnose compiler and serial port conflicts, and implement the gestural scale mapping algorithms.

## Results

What came of it. Include the things that did not work; a negative result you can describe is worth more than a success you cannot explain:
- **Positive Results:**
  - The AMY synthesis engine compiled cleanly with ESP32-S3, outputting glitch-free audio over I2S at 44.1 kHz without starving the main application loop or display refresh.
  - Physical tilting of the device immediately shifts scale degrees: tilting left smoothly steps down toward `C3`, level posture holds `C4`, and tilting right steps up to `C5`.
  - Pitch tilt forward or backward triggers clean octave shifts while dynamically opening the filter cutoff for bright lead sounds or closing it for mellow bass/pad tones.
  - The display runs smoothly at ~40 FPS, providing immediate visual confirmation of musical notes, octave states, and sensor angles.
- **Negative Results & Troubleshooting:**
  - COM Port Contention PermissionError: Access is denied: Initial firmware upload failed because the Arduino IDE Serial Monitor held an open lock on `COM3`. Closing the Serial Monitor immediately freed the USB-CDC interface for `esptool`.
  - External DAC Pivot: Tried connecting an external Adafruit UDA1334B I2S DAC, but decided to leverage the onboard ES8311 codec and built-in power amplifier, eliminating external breadboard wiring clutter and focusing on gestural scale control.

---

## Reflection

**What worked:**
- Dual-core task distribution on the ESP32-S3: running AMY DSP rendering on Core 1 while handling IMU sensor acquisition, EMA filtering, and ST77922 display drawing on Core 0 eliminated audio dropouts and stutter.
- The Exponential Moving Average filter successfully tamed jittery IMU noise, making musical note transitions deliberate and stable when holding a position.
- Combining the onboard ES8311 codec with the shared I2C bus worked seamlessly alongside the LSM6DSOX without bus arbitration conflicts.

**What didn't:**
- Blindly cycling through notes in a timer loop felt detached and non-interactive; switching to continuous gestural mapping made the device feel like an authentic musical instrument.
- Using unconstrained gyro rates for pitch bend caused extreme pitch drift; constraining the gyro influence to a subtle vibrato envelope yielded far more musical results.

**What I'd do differently:**
- Implement selectable musical scales (Pentatonic, Blues, Dorian, Minor) toggleable via touchscreen or gesture rather than sticking solely to chromatic/major mappings.

## Next week

Two or three specific things, each with a date.

- [ ] **October 6, 2026:** Configure the LSM6DSOX built-in Machine Learning Core (MLC) / Decision Tree to classify discrete gestures (flicks, taps, shakes) to trigger note strikes, drum samples, or preset changes without loading the main CPU.
- [ ] **October 9, 2026:** Integrate a Bluetooth Low Energy (BLE) MIDI stack so a wireless MIDI keyboard can send Note-On/Off triggers to AMY while the handheld device simultaneously modulates parameters (pitch bend, filter sweeps, mod wheel).
- [ ] **October 11, 2026:** Build an on-screen touch GUI menu on the ST77922 display to save, load, and switch between different gestural mapping presets stored in flash/NVS.
