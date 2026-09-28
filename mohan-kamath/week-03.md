# Week 3 — Adafruit LSM6DSOX Integration on ESP32

**Name: Mohan Kamath**
**Credit hours: 2**
**Date: 9/25/2026**

---

## Goals

What you set out to do this week.

- Wire and establish communication between the Adafruit LSM6DSOX breakout and the ESP32 board.
- Write and flash a test sketch to poll raw 3-axis acceleration and angular rate readings over serial monitor
- Inspect output data stability, noise floor, and register polling reliability to prepare the pipeline for ML gesture feature extraction

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

- Connected the Adafruit LSM6DSOX breakout to the ESP32 via I2C
- Utilized the Adafruit_LSM6DSOX and Adafruit_BusIO Arduino/C++ libraries to interface with the sensor over I2C
- Implemented a basic serial streaming script outputting timestamped 6-axis readings at 115200 baud to observe raw values
- Used Gemini to troubleshoot I2C bus initialization parameters and help parse sensor configuration registers

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.
- Successfully verified I2C communication with the LSM6DSOX on address 0x6A using the I2C bus scanner
- Successfully streamed raw linear acceleration and angular velocity data over serial
- Encountered intermittent I2C timeout when polling the sensor at high frequencies while writing prints to the console. Polling had to be slowed down and properly throttled to prevent dropping packets
- Raw gyroscope values still suffer from drift over continuous integration, confirming that raw readings alone cannot directly control continuous synth parameters (like sustained pitch sweeps) without filtering.

---

## Reflection

**What worked:**
Using the official Adafruit LSM6DSOX library made initial sensor configuration and register bring-up much faster than manually handling raw registers.   
Physical wiring and standard I2C bring-up were straightforward on the ESP32.
**What didn't:**
Attempting to poll sensor data too fast in an unthrottled loop caused I2C bus hangs and serial monitor bottlenecking.
Directly inspecting raw values confirms that without baseline calibration and filtering, raw sensor reads are still too noisy for direct audio parameter control
**What I'd do differently:**
Establish a non-blocking timer for sensor polling rather than a basic delay loop to maintain a stable sample rate for future ML preprocessing.
Implement a quick static calibration routine at startup to calculate and subtract zero-rate gyro offsets.
## Next week

Two or three specific things, each with a date.

- [ ] Implement a software low-pass / complementary filter on the ESP32 to smooth LSM6DSOX tilt and angular rate data — 9/29/2026
- [ ] Format and serialize sensor feature vectors (accel + gyro) over serial/I2C to pass into the team's initial ML gesture classifier — 10/02/2026

## Meeting notes

Anything from class worth keeping.
