# Week 6 — Hitting the ground

*Copy this into a new file in your folder and fill it in. Plain sentences
under the headings are fine — you do not need to know any formatting.*

**Name: Talal Masood**
**Credit hours: 2**
**Date: 10.15.26**

---

## Goals

- Finalize proposal.
- Interface in some way with IRIS to understand its capability and get practice in with using it.

## Methods

- We met Monday in the Hive again for an extremely productive session where we as group finalized our project idea along with a timeline and given individual roles.
- I utilized stranded-core wire and another ESP32S3 I have (with more pin capability) from my Embedded Systems class, coupled with IRIS, to create a capacitive touch experiment in order to understand how we can create the glove interface of the instrument. I used the serial monitor to read values from 3 wires to judge how much it changes when I touch the end of the wire, then click the boot button on the ESP32 as a way to train the IRIS algorithm so it knows when I actually touched the wire.
  -  The idea behind this is that we take advantage of the capacitive-touch-pins on the ESP32 using wires in order to create an interactive glove. A capacitive band would sit across the glove and measure the change in capacitance when each finger is moved down.

## Results

- We resulted in a solid and fun idea of a spinning chain instrument, which would use sensors (accelerometer and gyroscope) placed at intervals on the chain to take in data and create a continuous sound (likely with granular synthesis), and take user input from the gloves as a way for the user to create a distinct rhythm with discrete notes. The user can change the base sound based on how they are spinning the chain.
- In terms of the capacitive wire touch experiment, I was able to read values from each wire using pins 6,7, and 8, and discern a noticeable change from when each wire is touched versus left alone.
  -  I tried to also measure if there was a difference in charge when the wire was folded rather than touched, and I found that it worked some of the time, but it was difficult to move the wire back up in its original position. The idea behind this was to mick the movement of a finger, because at the time my vision was for each finger to have its own wire.
  -  However, a likely better idea is to have a wire across the palm (will likely need to be thicker rather than just one wire) and to measure the change in capacitance with each finger movement, then train IRIS to understand which finger was moved.
  -  On top of that, it might just be easiest to hardcode values for each finger based on the change in capacitance. For example, index finger is lowered when time to build charge is greater than 60,000 nanoseconds. 

- Here is a picture, I wired stranded wire with jumper cables because they were easier to insert into the breadboard.
<img width="3000" height="4000" alt="PXL_20261015_172928494" src="https://github.com/user-attachments/assets/c7e35060-e66d-48ad-8768-f6da3fabc12d" />
<img width="525" height="313" alt="Screenshot 2026-10-15 at 1 36 53 PM" src="https://github.com/user-attachments/assets/a4b26c9e-5c2f-46a8-92d0-b9f40bc33cb5" />
<img width="545" height="275" alt="Screenshot 2026-10-15 at 1 37 04 PM" src="https://github.com/user-attachments/assets/c39ba3d1-b1de-4530-97a9-b80e71f5011c" />



---

## Reflection

**What worked:**
- Meeting in the Hive to create a solid idea worked out well. We now have a good plan and course of action.
**What didn't:**
- I wanted to try and interface IRIS with sensor data but I didn't have any sensors with me. I also wanted to create an actual glove prototype but I didn't have a mitten/glove with me to attach the wires on. I tried to attach them directly onto my fingers but it proved difficult and also messed with the capacitive touch process as it was too close to my skin (which is very conductive).
- I also didn't really interact with IRIS as much as I wanted to, the code was running with any errors, so I assumed it was working and focused my attention towards the hardware side rather than software.
**What I'd do differently:**
- Prepare parts better and also plan out what I need beforehand so I can ask my teammates or professors for resources. 
## Next week

Two or three specific things, each with a date.

- [Prototype chain with sensors attached on it, try to train IRIS to know when the chain is in different positions and which way it is spinning]
- [Interact with IRIS more, rather than focusing on just the hardware side]
- [Map out functions for the instrument (how many notes do we want?, what finger gestures do we want?, how many sensors do we want across the chain?, where are we going to place the microcontrollers across the instrument?, how do we want to design the glove?). Mainly, there are still a lot of design questions left to answer]

## Meeting notes

Anything from class worth keeping.
