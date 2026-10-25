# Week 7 — Accelerometers

*Copy this into a new file in your folder and fill it in. Plain sentences
under the headings are fine — you do not need to know any formatting.*

**Name: Talal Masood**
**Credit hours: 2**
**Date: 10.22.26**

---

## Goals

- Interface the accelerometer with IRIS and attempt to train it on simple swinging gestures
- Acquire more components (mostly wiring) necessary for prototyping

## Methods

- I attempted to use ESPNow to connect two ESP32S3s together, with one connected to an accelerometer mounted to a breadboard, and the other connected to my computer to receive data and send to my computer.
- I used IRIS as the ML algorithm responsible for training the planned gestures to test. Gestures that can be determined utilizing accelerometer data include:
  - Swinging right to left, swinging forward and backward, vertical bouncing, and stationary hanging
- Hardware components include:
  - Two ESP32S3s, one with a display and I2C JST connection, the other with regular pins and no display.
  - Jumper wires
  - One LSM6DSOX accelerometer + gyroscope


## Results
- I could reliably power the accelerometer, and connect the two ESP32s via ESPNow; however, unfortunately I could get the accelerometer to properly work using jumper wires due to a likely unstable connection with the pins, as the accelerometer is unsoldered and does not support a JST connection, rather it supports a Stemma connection.
- Because of this, I wasn't able to train the model like I planned to.
- Here's a photo of the hardware setup:
<img width="900" height="1200" alt="PXL_20261023_032115064" src="https://github.com/user-attachments/assets/51724ddc-ab8a-4fee-8e2b-0e0b7ceffbe6" />


---

## Reflection

**What worked:**
- I was able to successfully connect my two ESP32s, flash code, and power my IMU (accelerometer).
**What didn't:**
- I wasn't able to reliably get data from the accelerometer due to a rather amateur way of connecting to it.
- I also wanted to properly harness the IMU/breadboard to a wire (likely my charger cable) but the wire setup was proving to be too unstable to handle erratic movements.
**What I'd do differently:**
- Understand what components and wiring I need by the previous meeting so I can have it for the week going forward.
## Next week

Two or three specific things, each with a date.

- [ Kyle provided me with the proper wiring connections (multiplexer, stemma cables, and also key switches, so I will be able to properly attempt to train swinging gestures with IRIS (yay!)]
- [ I found out that the accelerometer is actually a whole IMU unit including a gyroscope as well. So I will be able to train even more gestures that an accelerometer cannot provide data for on its own. This is also good news since we won't have to buy gyroscopes separately.]
- [ We will be meeting to discuss the proper circuitry and wiring of the instrument, and will be working with the printed chain prototype Caleb made, and experimenting with the granular synthesis patch Sam is developing.]

## Meeting notes

Anything from class worth keeping.
