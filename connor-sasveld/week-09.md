# Week 9 — "Finalizing" the UI

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 11/6/2026

---

## Goals

What you set out to do this week.

This week, I set out to finish the UI for our synth, which includes making a good draft of the layout of our synth. I also wanted to get some work done implementing AMY.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I used AMY documentation to figure out what parameters were available to use, and I continued using EEZ studio and its documentation to create the UI elements. I also used Claude to help me route UI elements to the variables I wanted changed, and also to help me figure out how to do some more complex LVGL UI techniques.

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

I decided on a 5 page design for sound synthesis with a Mix page for mixing through the three FM oscillators; a Source page where you can edit the ratio, mod index, and feedback of each oscillator pair; a filter page where you can choose between filters for each for each of the oscillator pairs and a global cutoff and resonance; a Motion & FX page where you can apply vibrato, detune, chorus, reverb, and echo; and finally a pitch page where you can decide between AMY playing a scale, a quantized programmable pitch control, or a continuous programmable pitch control. The user can define the scale, the root note, and the pitch range.

Each of the sound design menu items are located in a navigation bar at the bottom. In the top right, there is a presets button that takes the user to a menu where they can save, load, edit, and delete presets. When the user goes to save a preset, a keyboard comes up where they can decide on the name. When they want to delete a preset a message comes up that confirms they actually want to delete the preset.

I did not get to any of the IRIS implementation this week primarily because my group wasn't able to meet during this week. Hopefully we can carve out some substantial time this weekend to put all the pieces together, but overall, I think we are in a really good place for our prototype deadline.

My code is in the GutterballUI3.5 directory in the group-2 instruments dir. I have a description of the necessary libraries that are needed.

---

## Reflection

**What worked:**

This was probably the most smooth sailing week out of any of them. No fumbling around with libraries, I already had a decent understanding of how to use EEZ, it was just me figuring out how to make a good UI for this synth, which was very fun.

**What didn't:**

Like I mentioned in the results section, I wasn't able to implement IRIS at all because I couldn't meet with my group and therefore I didn't have access to any sensors to make sure everything was working while I was coding.

## Next week

Two or three specific things, each with a date.

- [ Meet with my group and start putting pieces together/implementing IRIS 11/7 or 8/2026 ]
- [ Once IRIS is implemented, test each parameter with a basic one sensor test to make sure they all work, then start trying them in tandum 11/10 or 11/2026 ]

## Meeting notes

N/A
