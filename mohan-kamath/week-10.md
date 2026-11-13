# Week 10 — Iris implementation

**Name:** Mohan Kamath
**Credit hours:** 2
**Date:** 11/13/2026

---

## Goals

Use Iris to learn a mapping from motion to sound. Build a computer interface
for recording poses, editing keyframes, and hearing the learned mapping.

## Methods

The ESP32-S3 Feather sent motion samples from the gyroscope sensor over ESP-NOW
to the 2.8-inch ESP32-S3 receiver. I flashed both boards with
Arduino CLI. The receiver calculated roll and pitch from acceleration.

In the GUI i made for training iris on PC, each keyframe pairs roll and pitch with a chosen MIDI
note and volume. The app sends the examples to the receiver, where Iris
trains and predicts. The app converts the predicted note to frequency and
plays a sustained sine tone at the predicted volume.

I used OpenAI Codex to help build the Windows GUI.

## Results

The Feather captured 616 samples at 102.52 Hz with no missing rows or
sensor read errors. The receiver trained on four test keyframes and produced
594 live predictions. Predicted notes ranged from MIDI 48 to 72 and volume
from 15% to 85% as the sensor moved. The receiver also reported 32 stale
readings when fresh motion was unavailable.

The original MIDI preview decayed while I held a pose. I switched it to a
continuous sine tone that follows predicted pitch and volume.

Here is a pic of the GUI that I intend to put on the ESP with display:
<img width="1601" height="1022" alt="image" src="https://github.com/user-attachments/assets/aecf8c09-25fe-421c-9a82-e14428fc2a98" />


---

## Reflection

**What worked:** The GUI let me pair poses with sound settings and watch the
receiver's predictions change as the sensor moved.

**What didn't:** The first preview faded during a held pose, and the gyroscope data wasn't clean and had a lot of stutter.

**What I'd do differently:** Test gyroscope motion more and tweak it so that it plays more smoothly.

## Next week

Two or three specific things, each with a date.

- [ ] November 16, 2026: Fix stutters in movement.
- [ ] November 19, 2026: build the iris training GUI for the ESP32 display

## Meeting notes

Anything from class worth keeping.
