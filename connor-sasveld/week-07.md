# Week 7 — Finally getting audio output FINALLY

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 10/23/2026

---

## Goals

What you set out to do this week.

This week, I wanted to finally get audio output, as well as set up an infrastructure that allows me to easily add UI elements that can control specific parameters in AMY.

## Methods

EEZ Documentation, AMY Documentation, especially for message generation. Again, I spent a lot of time this week pushing through problems with different libraries and hardware issues. I used Claude to help me isolate variables and come up with possibilities for what was going wrong. I also used Claude to help me format my logic, especially when it came to figuring out a way to set up my code so that I can easily add new parameters to control in the UI.

## Results

I put my code I ended up with this week in the AMYMultiParamTest folder in my notebook folder. I was able to get a script running that features two vertical sliders on my FNK0104 touchscreen, one for low-pass filter cutoff and one for resonance. The user can change the value of the sliders on the touchscreen. There is a visual indicator of the current value of each slider. The sliders are able to actually change the sound of an FM synth patch in AMY, and I am finally getting audio output.


---

## Reflection

**What worked:**

I was able to set up an effective system for creating a more complex UI that controls multiple AMY parameters, I also pushed through some troubleshooting struggle points which I will discuss in the section below.


**What didn't:**

For a long time, I would turn on my code and it would work for a few seconds and then freeze up. I tried a lot of things to get this to stop happening, but the culprit ended up being that I didn't have Serial Monitor open. The board would try to read the Serial Monitor but it wasn't there. I never would have thought that this would cause the software to freeze up in such an odd way, but here we are i guess. I added a line to my code that tells the board not to wait for information from the Serial Monitor, in case I want to run the program without opening a Serial Monitor.

I also figured one of the most frustrating things I've been dealing with for weeks, my inability to get audio coming out of the board. Turns out, the problem is that I had the wrong pins defined for my board. I don't think this is totally my fault though because the online example scripts for my 2.8inch board online actually use the pin numbers for the 3.5inch variant (which are different). Once I figured this out, getting audio output was pretty straight forward.

## Next week

Two or three specific things, each with a date.

- [ Learn how to create a multipage UI 10/24/2026 ]
- [ Work with Mohan and Aidan to connect my UI with Iris 10/26/2026 ]

## Meeting notes

In our meeting, we just generally discussed Iris, and I did some personal work on the project for a bit.
