# Week 6 — Getting Structured

**Name: Samuel Kuran**  
**Credit hours: 2**  
**Date: 10/15/26**  

---

## Goals

- Meet with Caleb and Talal at the HIVE - Monday 10/12
  - Finish the instrument worksheet, thus solidifying our project idea
  - Assign roles
  - Create 1 main goal and 1 stretch goal per week to get to first prototype
  - Update the project proposal template.
- Complete your portion of the first main goal - Thursday 10/15

## Methods

- Met with Caleb and Talal at the HIVE - Monday 10/12
  - Finished instrument worksheet, assigned roles, created 1 goal and 1 test of that per week.
  - Updated project proposal template
- Completed the "connect ESP-32 to max" portion of my main goal. Did not connect to wifi.
  - Created a starter-sound max project to pair with the sonar_screen code, that processes the cm distance sent over serial, and sonifies it in the aesthetic of a metal detector. (The synthesis was more proof of concept than for the instrument itself)
  - I started a README for it, describing how to set it up.
- In the instrument > group 1 > README, I added a place for us to list material needs for our instrument.

## Results

- My role going forward is to work on connecting the ML and synthesis aspects of the instrument, since I have the most audio programming experience.
- I struggled with troubleshooting the serial to max connection, which I've heard is not uncommon. Through forums and trial and error, I learned some of the pitfalls, like how you cannot have the Serial Monitor running while trying to send it to Max (I had it running to debug, ironically). I posted this info in the resources tab to help others.
- I was ultimately successful in getting the sensor data in Max. We can now move towards developing the ML mapping system and concurrently, a suitably flexible synthesis system.
  - It's important to smooth the data of the serial input to avoid popping from amplitude discontinuities.
Here's an image of the main patch.
<img width="632" height="800" alt="Screen Shot 2026-10-16 at 7 02 46 PM" src="https://github.com/user-attachments/assets/0050c91f-9be3-477b-86e6-e46ae9e14900" />


---

## Reflection

**What worked:**  
Meeting on Monday was great for getting us aligned and motivated, leaving us time to work independently before Thursday.

**What didn't:**  
- Currently, it will be hard for people to access my starter-sound-patch on the online github, because it's hard to download a directory. For efficient and safer code collaboration, each of us will need to clone the instrument > group 1 folder. Kyle has given me a nice terminal command to help!
- Frequently while connecting serial to max, my USB disconnected from the computer. I might look into a solution.

**What I'd do differently:**  
Still need to get notebook in before Thursday meeting.

## Next week  

- Group Goal: Finish CAD design V2 and begin attaching hardware devices to the physical product. Have an ML patch that runs without bugs. Have a starter synthesis patch - Friday 10/23
  - Personal Goal: Contribute to starter ML and synthesis patches.
- Meet with Caleb and Talal at the HIVE - Monday 10/19 7pm
  - Work on the decision points of the instrument: how many sensors, how each gestural motion should affect the sound, length of the chain, synthesis method(s), role of the gloves etc.
  - Figure out a plan with Talal on how we will work together on the ML patch. 

## Meeting notes

- Kyle showed us an ML-driven instrument he made. It was very cool to see the ML in action.
- Connecting IRIS and Max/Pd is something Kyle has yet to do, so it would be good.
  - If you have the time, an iris object would be even better.
- The IRIS ML system is small enough to support training in device. That is a cool feature to consider if our mapping ends up small enough.
