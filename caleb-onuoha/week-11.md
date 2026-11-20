# Week 11 — Making it Functional

*Copy this into a new file in your folder and fill it in. Plain sentences
under the headings are fine — you do not need to know any formatting.*

**Name:**  Caleb Onuoha
**Credit hours:** 1
**Date:** 11/16/26

---

## Goals  

Our goal as a team was to finalize and make our model functional to the point that the other group would be able to pick it up and play it.
My individual goal was to complete the models wiring and connect all the gyroscopes, the ESP32, and the multiplexor across the board. Another goal of
mine was to update the CAD model so that it would address all the limitations and "bumps" that we found with the original tested design.

## Methods  

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.  

I soldered together loose wire to the STEMMA QT cables to increase the length of the wires across the model so that there would be enough slack to prevent
the instrument from being restricted by the wires. I then wrapped electrical tape around the individual wire connections to prevent the chance for
cross-current flow to occur between the pins. Afterwards I utilized shrink wrap to keep the wires in order and then taped the sections with the heat shrink
wrap to the desired parts of the model so that they flow together.

There was an issue with 2 of the 4 pins on one of the ESP32 Feather's that we had so I had to reallign the pins to allow for the connections and current
to function as they were intended to.

It was determined that The ESP32 feather will require a powersource to function as it cannot remain connected to laptop/computer during demonstration, requires the inclusion of a battery pack which will be wired to a USB type A female breakout with a type A to Type C wire for connection to the ESP32 Feather. I initially attempted to use a dual AA battery holder but that only supplied a maximum of three volts which wasn't enough to supply constant power to the circuit. I then used a four battery AA battery pack with three batteries to supply four and a half volts, and connected the last battery holder section with a wire to complete the series circuit and allow current to flow and voltage to be supplied, without overheating or burning out the circuit.

## Results  

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.  

The physical model is not complete aside from the finalized CAD model which is the next part that I will be working on. The only thing in question is making
sure that the gyroscpopes, multiplexor, and ESP32 Feather remain in place throughout use of the instrument.

The power situation was solved with inclusion of the battery pack, with this inclusion I will also have to make adjustments to the CAD model to allow for a proper place of incusion for the battery pack.

## Reflection  

**What worked:**  We met together as a group the night of 11/16/26 (Monday) which was extremely useful and we were able to make a lot of progress 
together as a group. We plan to meet more times this week as a group in order to complete the project. We met together on 11/17/26 (Tuesday) in order to conitnue working on our project, we are much more effective and efficient when we work together as a group and it has proved to be incredibly useful.

**What didn't:**  As much time as we spend working, time also plays to be the main restrictor to our work, it feels as if there is never enough despite how
much we put in. A lot of the wires also kept breaking under stress or even sometimes when the instrument was not in use, this reveals an issue that lies in how the current instrument was put together, the soldering could be weak/not extremely well done or the wires themselves could be easy to split. Needs to be addressed to prevent further issues.

**What I'd do differently:**  This week I don't think there is much that I would've done differently, it was one of our best working weeks both as a group and individually and we were able to achieve results that were directly in line with our intial planning. If anything I would need to take a lot of times to solder the wires in a more "professional" way to ensure that wire splitting/breaking isn't one of the worries that we have.


## Next week  

Two or three specific things, each with a date.  

- [ Resolder the broken parts of the wire and try to ensure that it won't continue to break. (11/30/26) ]
- [ Work on Updated CAD Model (11/27/26) ]

## Meeting notes  

Anything from class worth keeping.  
