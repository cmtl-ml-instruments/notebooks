# Week 6 — Gesture Calibration

**Name:** Mohan Kamath
**Credit hours:** 2
**Date:** 10/16/2026

---

## Goals

This week I aimed to improve the stability of gesture-controlled musical notes and add calibration for neutral playing posture and gyroscope offsets.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I added a stationary calibration routine that collects sensor readings, estimates gyro bias, and establishes neutral roll and pitch. The synth remains muted during calibration, and movement outside the acceptance thresholds resets the sampling window. I also implemented labeled six-axis sensor recording and a PowerShell tool to save CSV data and calibration logs for fine tuning.

## Results

I successfully compiled the updated ESP32 firmware and checked the recording script’s syntax and implemented neutral-posture calibration, gyro-bias correction, note/octave hysteresis, and labeled sensor recording.

Hardware testing remains pending; the firmware has not been uploaded, and no gesture dataset has been collected.

I deferred external DAC testing until another cable is available.



---

## Reflection

**What worked:**

Separating calibration, gesture mapping, and recording made the firmware easier to reason about. Reviewing the mapping exposed a neutral-note mismatch, while adding raw sensor recording creates a way to evaluate future gesture models using measured data.

**What didn't:**

I haven't validated that the calibration feels natural or if the note transitions are stable.

**What I'd do differently:**
I would like to have tested on device much earlier to gather data and improve functionality sooner.

## Next week

Two or three specific things, each with a date.


- [October 20, 2026]: Upload the updated firmware and test stationary calibration, neutral C4, note boundaries.

- [October 22, 2026]: Collect short labeled gesture segments across multiple sessions and inspect timestamps.

## Meeting notes

Anything from class worth keeping.
