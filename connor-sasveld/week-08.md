# Week 8 — Multi Page UI and preperation for implimenting AMY and IRIS

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 11/1/2026

---

## Goals

What you set out to do this week.

This week, I wanted to set up the infrastructure to create a multipage UI that allows for IRIS and AMY use.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I mainly used EEZ documentation, this week I just figured out how to make multi-page UIs and put buttons across all pages. It also took me some time
to modify my existing code to work with the 3.5 inch board (I had been using the 2.8 inch board up until this point).

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

I was able to get everything running corredctly on the new board in terms of the display and touch screen. I also figure out how we will organize
the synth. I think we're going to have three pairs of FM operators that the user can program seperately and mix together. My current idea is that we will
have a mix page where you can program the volumes of each of the oscillators; a sources page where you can control the ratios, mod index, and feedback
of each pair of oscillators; the tone page where you can control a lowpass filter's cutoff, resonance, vibrato depth, vibrato rate, and detune;
a global page where you can control the volume and scale/octave range; and then a presets page where you can save and recall models.

All I actually got done this week is the Mix page, but I figured out how to make a multi-page UI and buttons that can be on top of all the pages.

---

## Reflection

**What worked:**

I got the display and touch screen working, and I set up the infrastructure to create a fully fleshed UI with the capacity to easily impliment
AMY and IRIS in tandum.


**What didn't:**

I wanted to get more work done on the actual UI design, but setting up the the libraries for the new board took longer than expected.

## Next week

Two or three specific things, each with a date.

- [ Finish the UI design 11/3/2026 ]
- [ Connect all of the UI elements to actual AMY parameters 11/5/2026 ]

## Meeting Notes
N/A
