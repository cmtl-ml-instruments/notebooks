# Week 2 — Brainstorming

*Copy this into a new file in your folder and fill it in. Plain sentences
under the headings are fine — you do not need to know any formatting.*

**Name: Aidan Kenny**
**Credit hours: 1**
**Date: 9/17/26**

---

## Goals

What you set out to do this week.
My goals this week were to get more familiar with the esp32 board and to brainstorm/research potential instruments.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

The first idea that came to mind was using gravity/tilt as the primary sensor that controls pitch. I googled instruments that use such technology and found an article (https://newmusicusa.org/nmbx/american-innovations-in-electronic-musical-instruments/10/) that mentioned an instument called the "Hands" created by Michel Waisvisz. I asked gemini to find me an article that had more information and found a pdf explaining them: (https://www.jaimeoliver.pe/courses/ci/pdf/waisvisz-1985.pdf)

As for the board, I was having difficulty setting it up. I have lots of experience programming arduinos in the IDE so it was troubling to be struggling. I was able to add the board but the problems came when I tried to upload my program onto it. I was unable to get it to work in the end, but it will be the first thing I work on this week.

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

My biggest takeaway this week was learning a lot about Michel Waisvisz's hands. They were created with the intentions of letting the composer "touch" and manipulate sound in real time. The hands were two metal plates that could be strapped to the wrist. The artist can then use their fingers to press the 12 keys on each plate. The cool part of the device is that it used 4 mercury switches per hand to detect arm position as well as tilt. This data would then correspond to the octave of the resulting sound. As for how it works, the sensors on board collect data related to 3 things: Finger Keys (Pitch), Mercury Tilt Switches (Octave Shift), and Sonar Ultrasonic Pulse (Distance). These are then sent to the microprocessor that converts the data to MIDI data bytes. The MIDI out cable then connects to seperate speakers that produce the resulting sound. I plan to pitch this concept to my team and discuss potentially incorporating some of these features to our instrument.

---

## Reflection

**What worked:**
I was able to get some good research done and learn about a potential instrument model.

**What didn't:**
My problem solving with the esp wasn't very successful.

**What I'd do differently:**
I just need to power through and figure out why my programs aren't uploading to my esp. I plan on using AI and my groupmates to assist if I can't figure this out on my own.

## Next week

Two or three specific things, each with a date.

- [Get my esp32 functional] - 9/25/29
- [Finalize a instrument idea and work on a pitch] - 9/25/19

## Meeting notes

Anything from class worth keeping.
