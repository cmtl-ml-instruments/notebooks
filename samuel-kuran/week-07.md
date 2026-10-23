# Week 7 — Learning Sensors and Synthesis

**Name: Samuel**  
**Credit hours: 2**  
**Date: 10/22/2026**  

---

## Goals

- Group Goal: Finish CAD design V2 and begin attaching hardware devices to the physical product. Have an ML patch that runs without bugs. Have a starter synthesis patch - Friday 10/23
  - Personal Goal: Contribute to starter ML and synthesis patches.
- Meet with Caleb and Talal at the HIVE - Monday 10/19 7pm
  - Work on the decision points of the instrument: how many sensors, how each gestural motion should affect the sound, length of the chain, synthesis method(s), role of the gloves etc.
  - Figure out a plan with Talal on how we will work together on the ML patch. 


## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

- Cloned our group1 folder and updated the starter sound patch. Added .gitignore file to our instrument repo for .DS_Store
- Took notes on hardware page, looking for the most important items we need
- Took notes on the [LSM6DSOX 6 degrees of freedom accelerometer/gyroscope](https://learn.adafruit.com/lsm6dsox-and-ism330dhc-6-dof-imu/arduino) (6Dof). Installed the required libraries.

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

- I realized that a multiplexer will be essential to our instrument design, involving multiple 6Dofs.
- The I2C connectors I have for the sonar sensor seem too big for the 6Dof, so I was not able to connect the 6Dof to my ESP32.

---

## Reflection

**What worked:**  
I learned Adafruit has [great documentation](https://learn.adafruit.com), covering their parts from the pin layout to the arduino examples. I will continue to use this as a resource.

**What didn't:**  


**What I'd do differently:**  

## Next week

Two or three specific things, each with a date.

- [ ]
- [ ]

## Meeting notes

Anything from class worth keeping.
