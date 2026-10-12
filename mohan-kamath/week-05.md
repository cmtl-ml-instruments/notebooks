# Week 5 — External DAC Integration & Headphone Audio Preparation

**Name:** Mohan Kamath
**Credit hours:** 2
**Date:** 10/11/2026

---

## Goals

- Prepare the ESP32-S3 to send AMY synthesizer audio to the external Adafruit UDA1334 DAC.

- Determine the hardware needed for clean headphone playback.

- Create a standalone audio test before integrating the external DAC into the gesture-controlled instrument.

## Methods

- Consulted [Adafruit’s UDA1334 documentation](https://learn.adafruit.com/adafruit-i2s-stereo-decoder-uda1334a/pinouts) to verify power, digital audio connections, output limitations, and clock requirements.
- Created a separate test sketch using the [AMY synthesizer library](https://github.com/shorepine/amy). The sketch generates a low-amplitude 440 Hz sine wave, starts muted, and accepts serial commands for tone playback, mute, and left/right channel checks.
- Inspected the installed AMY library and found that its internal ESP32 audio driver uses MSB-aligned output. Configured the test to send samples through a separate Philips-format I2S channel matching the DAC’s default input format.
- Used Codex to review the firmware, research DAC requirements, and debug the test sketch.

## Results

- the DAC provides line-level output and is intended for a separate amplifier. Adafruit reports that directly connecting typical 32-ohm headphones can cause current limiting and distortion.
- the documentation revealed that the DAC does not require an external MCLK connection.
- Prepared the standalone test sketch and instructions without changing the main instrument firmware.
- External DAC audio output and stereo channel operation remain unverified.

---

## Reflection

**What worked:** 
Reviewing the DAC documentation clarified the distinction between converting digital audio to an analog signal and supplying enough drive for headphones. Separating the audio test from the display and IMU should make troubleshooting easier.

**What didn't:**
The DAC and headphones alone do not provide the intended clean headphone playback setup. Compilation also remained incomplete, preventing firmware validation and hardware testing.

**What I'd do differently:**
Check the output load requirements and connector accessibility before planning the full integration. Verify a fixed test tone through the complete headphone audio chain.

## Next week

Two or three specific things, each with a date.

- [ ] **October 13, 2026:** Confirm accessible I2S GPIOs and identify a stereo headphone amplifier with a line input and volume control.
- [ ] **October 15, 2026:** Complete compilation, wire the DAC, and test the 440 Hz tone and stereo channels through the headphone amplifier.
- [ ] **October 16, 2026:** If the standalone test passes, integrate the external DAC output into the gestural synth and check for noise, distortion, and audio dropouts.

## Meeting notes

Anything from class worth keeping.
