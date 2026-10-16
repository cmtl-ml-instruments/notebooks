# Week 6 — Learning how to use LVGL

*This is your notebook for week 6. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 10/15/2026

---

## Goals

What you set out to do this week.

This week, I set out to learn how to use the LVGL library to design our UI. I think it will be the most streamlined way to handle a bunch of sliders and toggles and such controlling different parameters of the AMY synth.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

LVGL Library: https://github.com/lvgl/lvgl
EEZ Studio: https://www.envox.eu/studio/studio-introduction/
Freenove LVGL Documentation: https://docs.freenove.com/projects/fnk0104/en/latest/fnk0104/codes/MAIN/13_LVGL.html

I used AI to help explain the functions that are used to initialize LVGL for use on the ESP32. I had it tell me what the arguments are, why they need to be the data types they need to be, and what role they play in initializing LVGL.

## Results

I was able to design a simple one slider UI in EEZ studio and then port it over to the ESP32 screen. I also got the touch screen working so the user can interact with the slider. I got here after hours of figuring out how to properly get both LVGL working and the touch screen working without any graphical glitches. It took me a long time to figure out how to make the touch screen accurate to where my fingers are on the screen.

---

## Reflection

**What worked:**

I was able to design a UI in EEZ studio, export the LVGL code, get it running on the ESP32 display, and then make it so the user can interact with the slider on screen.


**What didn't:**

I really wanted to get to a point where I could have a slider that displays its own value and updates a parameter in AMY, but I couldn't quite figure out how variables work in EEZ studio. It also took me hours of trial and error trying to get these libraries to properly work for my board, similar to weeks past.

## Next week

Two or three specific things, each with a date.

- [ Figure out how variables work in EEZ studio 10/19/2026 ]
- [ Create a UI that allows to control at least 12 parameters of an AMY Synth with multiple pages 10/22/2026 ]

## Meeting notes

In our last meeting, we discussed the form of our project. We decided to use to ESP32s. One that the user actually moves around through space which sends the accelerometer and gyroscope data to another ESP32 that does the synthesis and ML logic, it will also have the UI on the screen. We talked about making a bowling ball case for our synth cause we thought it would be fun and make it more intuitive for the user to pick up.
