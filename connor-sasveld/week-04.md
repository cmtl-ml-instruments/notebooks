# Week 1 — Exploring AMY on the ESP32 (Figuring out how to get the software to run and output audio)

*This is your notebook for week 4. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 10/5/2026

---

## Goals

What you set out to do this week.

This week I set out to get AMY running on the ESP32, just outputting basic audio.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I have never learned C++, and I don't know anything about the AMY library or how embedded systems work, so I used Gemini pretty extensively to help me figure out how to make things work. I would ask it how to structure the logic of taking in a MIDI input, starting the AMY synth up, processing the MIDI information, and outputting audio. I would then ask lots of follow up questions about the syntax of the code blocks it gave me and how they work, which are included in my script. I would then compile the code and try to fix most of the logic errors that I could by myself, but sometimes I would get an error because Gemini tried using functions that don't exist, and so then I'd ask it to reference the documentation of whatever library that was being used and explain what function should be used to achieve the desired result.

## Results

I didn't have much time to work on my goals since I had midterms and also left for NYC on Thursday. I also had trouble with the USB cable I brought with me on my trip and my computer was struggling to connect with the ESP.

All of that to say, I did not get audio output this week. But I did get a good start on it, and I have a much better understanding of how the logic flow works in the Arduino IDE for this type of application.

Here is the code I ended up with:
<img width="1824" height="1414" alt="image" src="https://github.com/user-attachments/assets/5a87e385-7e1f-4d49-9f8d-f663a3a34129" />

---

## Reflection

**What worked:**
I think the structure of having a detailed conversation with Gemini about the details of how two format the logic and syntax of this starter code was very helpful for me learning how to code for embedded systems in C++. It was actually really helpful when it would give me functions that didn't exist because I had to question it and once it found the correct function I was able to deeply understand how it is supposed to work. I think that once I get a better cable, I will be able to quickly get sound out of my ESP32.

(I'm pretty sure it's the cable because I've had problems with it for other applications)


**What didn't:**
I wasn't actually able to get sound out of my board, but, again, I think with a better cable that problem will be solved.

## Next week

Two or three specific things, each with a date.

- [ Actually get audio coming out of the board 10/6/2026 ]
- [ Explore the different synths and their respective parameters 10/8/2026 ]

## Meeting notes

My group got to finalize our initial goals for our instrument, which are obviously subject to change. And we now have a stronger foundation for our progress post-fall break.
