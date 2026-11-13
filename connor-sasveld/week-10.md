# Week 10 — Getting IRIS working with AMY

*This is your notebook for week 10. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 11/13/2026

---

## Goals

What you set out to do this week.

This week, my goal was to fully connect all the UI elements and their corresponding variables to AMY parameters. I also set up an IMU as the AMY inputs.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I finished a draft of the UI in EEZ Studio.
I used AMY documentation to understand how Wire messages work: https://github.com/shorepine/amy/blob/main/README.md

I used Claude to help me with variable scaling, connecting UI elements to variables, and learning about AMY, and how to code for Arduino, as well has
how to efficiently deal with the large amount of data. I also used it to help me learn about different parts of the LSM6DSOX library.

## Results

I actually got everything running. The ML definitely works, but it is a little finnicky. It's hard to tell if some of the problems and inconsistensies
have to do with the hardware or the software. But the actual synth stuff mostly sounds like it's working. I might have to introduce a limit on mod index
because it sounds like there is some weird aliasing going on, but other than that everything works and sounds pretty good in terms of UI design.

Also, another week went by where my group couldn't find a time to meet up and actually put all of our pieces together, so that is definitely something
that will need to happen this upcoming week.

---

## Reflection

**What worked:**

I got everything actually running. The UI accurately controls the synth, the synth sounds like how I would expect it to, and I got IRIS working
with the IMU controlling the synth parameters based on the learned poses.

The main things I worked on were connecting UI elements to the parameters from the PARAMS[] array, getting IMU data into the program, and getting IRIS
to recognize the inputs and parameters and get the UI elements to actually control the training.


**What didn't:**

Again, some of the ML interaction feels a bit inconsistent with what I expect when I use it. Sometimes it feels like I will record two poses and then
when I train the instrument and play it I don't get a big difference when I move between the poses. Or sometimes I get a big difference when I move
between one of the recorded poses and another pose that I feel like I didn't specifically record. It's hard to tell if it is a hardware problem and
the IMU gets confused really easily, or if it is a software bug. I'll need to do some more debugging.

Also, there is so much to learn and so many different types of data and library information and value scaling and everything. I tried my best to code
most meaningful things by hand even with AI assistance and to try to learn and understand how everything worked. (You can even see some comments I made
for parts of the code where I am making note of what certain syntax means or what the input and output of a function represent). However, it has been very
difficult to really retain and understand a lot of the complicated parts of the code. I understand most of what is going on from a macro perspective, but
I wish I had more time to really dig deep into how these libraries work and how to fully structure the data flow myself.

## Next week

Two or three specific things, each with a date.

- [ Finally meet up with my group and put all the pieces together/work out bugs 11/17/2026 ]
- [ Start getting non-musician and musician friends to test out the device and record their opinions 11/19/2026 ]

## Meeting notes

We talked about what implementing IRIS looks like for our individual projects.
