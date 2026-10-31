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

- Met with Caleb and Talal at the HIVE
- Cloned our group1 folder and updated the starter sound patch. Added .gitignore file to our instrument repo for .DS_Store
- Took notes on hardware page, looking for the most important items we need
- Took notes on the [LSM6DSOX 6 degrees of freedom accelerometer/gyroscope](https://learn.adafruit.com/lsm6dsox-and-ism330dhc-6-dof-imu/arduino) (6Dof). Installed the required libraries.
- Added my granular synth patch from Audio Tech I to the repo.
- I started brainstorming about what parameters would be controlled on the granular level versus the macro level

## Results

- At the meeting, we tried to envision how to play the instrument. I decided to focus on the synthesis so that we have something to connect IRIS to. We decided to spread 3 6dofs along the instrument to start.
- I realized that a multiplexer will be essential to our instrument design, involving multiple 6Dofs.
- The I2C connectors I have for the sonar sensor seem too big for the 6Dof, so I was not able to connect the 6Dof to my ESP32.
- I tried moving the starter sound patch using the `mv` terminal command, and almost lost my work. I learned that the `cp` command is far safer.
- Timbrally, I want the instrument to sound sparkly, and involve string bending.

---

## Reflection

**What worked:**  
I learned Adafruit has [great documentation](https://learn.adafruit.com), covering their parts from the pin layout to the arduino examples. I will continue to use this as a resource.

**What didn't:**  
Connecting the 6dof failed, but Kyle helped us after our meeting.

**What I'd do differently:**  
Ensure hardware needs are met at the subgroup meeting at the HIVE.
## Next week

Two or three specific things, each with a date.

- Group Goal: Print out the CAD Design. Finish starter synthesis patch. Start the ML Patch.- Friday 10/30
  - Personal Goal: Finish the starter synthesis patch.
- Meet with Caleb and Talal at the HIVE - Monday 10/26 7pm
  - Solder STEMMA QT to JST for the 6dof
  - Update weekly goals
  - Discuss wiring instrument

## Meeting notes

- Kyle gave us some STEMMA QT which are necessary to connect with the 6dofs
- Kyle gave us the 8-channel multiplexer which solves the problem of adding more than 2 6dofs. Thanks!
- Kyle showed us where to solder on the 6dof, so we can give it a new address. That will still be useful for starting with two 6dofs.
- We discussed how documentation and user testing will become a priority near the end of the semester.
