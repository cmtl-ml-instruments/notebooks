# Week 11 — Wireless Motion Control with Iris

**Name:**  Mohan Kamath
**Credit hours:**  2
**Date:**  11/20/2026

---

## Goals  

I set out to integrate the Feather’s wireless sensor transmission with Connor’s touchscreen GUI and Iris implementation. Then test the complete path from movement to learned sound changes.

## Methods  

Integrated the generated GUI files from our group repository with the supplied Iris implementation. The Feather transmits acceleration and gyroscope readings over ESP-NOW. The display calculates three smoothed acceleration components and rotation activity, which Iris uses to predict 18 sound parameters.

Flashed the boards individually, checked sensor readings over USB, and tested wireless reception with the Feather powered separately. I Recorded two poses with different A levels and tested whether the sound followed the movement.

Used Codex to inspect logs, diagnose failures, and test fixes.

## Results  

The complete sensor-to-sound system worked. The sensor produced approximately 102.5 samples per second with no missing samples during the capture.

---

## Reflection  

**What worked:**  I was able to successfully integrate the GUI with my Feather data transmission code and test it.


**What didn't:**  Tiny differences in nearly stationary inputs were magnified during learning, overwhelming the intended pose changes.


**What I'd do differently:**  Add clearer recording diagnostics and check sensor noise before training.


## Next week  

Two or three specific things, each with a date.  

- [ ] November 23 Test at least four distinct poses and check transitions between them.
- [ ] Test saving and loading learned presets and recovery after power cycling.

## Meeting notes  

Anything from class worth keeping.  
