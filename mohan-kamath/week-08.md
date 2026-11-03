# Week 8 — Wireless Communication

**Name:** Mohan Kamath
**Credit hours:** 2
**Date:** 10/30/2026

---

## Goals

What you set out to do this week.

This week I started to work towards making a two-board instrument. Having the smaller display-less ESP32 read sensor data and wirelessly transmit it to the ESP32 with a display which would eventually handle the machine learning and music synthesis.

My goals were to read all of the accelerometer and gyroscope data from the smaller ESP32, establish a wireless connection between the two boards, and verify that the received values matched the original measured ones.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I used ESP-NOW on channel 1 to send the measurements directly between the boards
without a router. Each packet includes the six sensor values, a sequence number,
an acquisition timestamp, and a boot/session identifier. The receiver checks
packet format and numeric values, tracks missing samples, and reports when
fresh data stops arriving.

I compared USB logs from both boards and used PowerShell test scripts to check
sample rate, data continuity, sensor errors, and received packets.

Resources and project files:

- [Adafruit ESP32-S3 Feather pinouts](https://learn.adafruit.com/adafruit-esp32-s3-feather/pinouts).
- [ST LSM6DSOX datasheet](https://www.st.com/resource/en/datasheet/lsm6dsox.pdf).
- [Espressif ESP-NOW documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/espnow.html).
- [Arduino-ESP32 source repository](https://github.com/espressif/arduino-esp32).


## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

The Feather transmitted all six sensor axes at 102–103 packets/second.
Five matching samples had identical values on both boards. The receiver logged
19,627 packets and four missing samples, with no queue overflows
in the final checks. Communication worked without an open Feather serial
monitor and recovered automatically after a restart.

Because I never used the 2.8 inch display before I couldn't get it to work which was irrelevant for the wireless communication test, so I removed display
support. USB buffering initially dropped readings and stalled reception;
sending output in smaller chunks fixed these issues. I still have to test out range, longer runs, iris,
and music integration.

---

## Reflection

**What worked:** 
Separating the boards' roles and comparing logged samples made communication
easy to verify.

**What didn't:**
The wrong display setup wasted time, and USB logging interfered with reception.

**What I'd do differently:**
Confirm hardware first, test communication before extra features, and check operation with serial monitors both open and closed.

## Next week

Two or three specific things, each with a date.

- [ ] November 2, 2026: Record tilts and rotations on each axis, and verify the received values.
- [ ] November 4, 2026: Run a 30-minute wireless test at several measured distances.
- [ ] November 6, 2026: Begin connecting received motion data to the existing gesture-to-note mapping

## Meeting notes

Anything from class worth keeping.
