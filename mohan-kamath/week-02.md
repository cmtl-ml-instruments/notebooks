# Week 2 — Hardware & Sensor Bring-Up (MPU-6050 Prototyping on ESP32)

**Name: Mohan Kamath**
**Credit hours: 2**
**Date: 9/18/26**

---

## Goals

This week, my primary goal was to take our team's shared concept of a handheld, gesture-controlled synthesizer instrument and evaluate the initial hardware viability. Specifically, I set out to:

1. Research viable IMU sensors and synth integration options on the ESP32 alongside the team.
2. Wire up an MPU-6050 6-DOF sensor to an ESP32 dev board over I2C on a breadboard.
3. Write, flash, and verify a firmware program to poll raw accelerometer and gyroscope data and evaluate sensor drift/noise for musical mapping.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.



Connected an MPU-6050 breakout module to the ESP32 via I2C with external pull-ups to 3. Wrote a C/C++ firmware sketch using the ESP32 I2C driver. Implemented serial output parsing to print 3-axis acceleration and angular rate readings over the serial monitor at 115200 baud.

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

Successfully detected the sensor on 0x68. Configured the internal sample rate divider and read out all 6 degrees of freedom at ~100 Hz.

The raw gyroscope values exhibit clear integration drift when static, which will cause synthetic continuous parameters (like pitch or sustained filter sweep) to wander if mapped directly without filtering.

Accelerometer data picks up hand tremors and physical button-press shock directly as high-frequency noise spikes.

Raw register values cannot be directly piped into synth control inputs. We will either need a complementary/Madgwick fusion filter on-chip or utilize the MPU's on-board Digital Motion Processor (DMP) to output clean values.

While the MPU-6050 works reliably for basic tilt and roll, Connor's research into 9-DOF sensors (like the MPU-9250 or BNO055) is worth keeping in mind if we need an absolute heading reference using a magnetometer without drift.

---

## Reflection

**What worked:**

Getting the I2C pipeline and MPU-6050 register readouts working on the ESP32 dev board was quick and straightforward.

**What didn't:**

Direct mapping of raw acceleration values creates jittery artifacts in audio parameters. A simple averaging filter helped slightly, but real-time latency vs. smoothing trade-offs will be an issue until we add a proper filter.

**What I'd do differently:**

Instead of rolling custom register reads from scratch, test the official I2Cdevlib / MPU6050 DMP library next time to get orientation calculations offloaded from the main ESP32 CPU core.

## Next week

Two or three specific things, each with a date.

- [ Test new Time of flight sensors with ESP — 9/22/2026]
- [ Read values and implement some signal processing — 9/25/2026]

## Meeting notes

Anything from class worth keeping.
