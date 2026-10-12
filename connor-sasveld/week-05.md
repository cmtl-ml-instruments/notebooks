# Week 5 — Troubleshooting all week

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 10/11/2026

---

## Goals

What you set out to do this week.

This week, I set out to actually get some audio coming out of the board. Long story short, I failed at that, but I made progress in other areas.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I used the Freenove ESP32S3 2.8 inch touch screen display documentation to figure out how to solve my issues with the display and touchscreen. I used EEZ to design and generate UI code in LVGL, and then I used the dimensions of that to make a UI using the Arduino GFX library. I'm also including the libraries I used for my touch screen.

https://docs.freenove.com/projects/fnk0104/en/latest/
https://github.com/shorepine/amy
https://www.envox.eu/studio/studio-introduction/
https://github.com/adafruit/Adafruit_ILI9341/blob/master/Adafruit_ILI9341.h
https://github.com/adafruit/adafruit-gfx-library
https://github.com/PaulStoffregen/XPT2046_Touchscreen

## Results

I tried getting audio to come out of my board and I was having a lot of trouble. I realized it wasn't worth my time figuring it out because Mohan already did that. So I started figuring out how to make an interactive UI on the touchscreen to interact with AMY parameters. I copied over Mohan's code and took out all of the audio output and sensor stuff because I wasn't able to get either of those things to work. And whatever libraries he was using to get the display to work was not working for me, so I had to change it to the Adafruit libraries for the screen and GFX.

I got a slider on the screen, and I made it so that it would theoretically change a filter cutoff when it's moved with the user's finger, but I couldn't get the touchscreen to work, so I'll have to figure that out next week. I consider this a success though because I went from not being able to get the display to work to being able to design something on the screen.

---

## Reflection

**What worked:**

I got my screen working and I got a slider on the screen with the infrastructure ready to have it be able to edit an AMY parameter.


**What didn't:**

I didn't get audio running out of my board and I didn't get the touchscreen working.

## Next week

Two or three specific things, each with a date.

- [ Get the touch screen working 10/13/2026 ]
- [ Make a more expansive UI, learn how to make pages 10/15/2026 ]

## Meeting notes

We talked about the creative vision of our project and came up with some clearer steps as to 
