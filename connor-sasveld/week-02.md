# Week 2 — Initial Research (Exploring some possibilities in terms of instrument design)

*This is your notebook for week 2. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 9/17/2026

---

## Goals

What you set out to do this week.

This week, my group set out to come up with some ideas we had for our project explore some avenues that we could take in terms of our instrument design. We compiled our ideas in our moodboard file in our group's GitHub folder

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

Our group had some conversations in our text group chat talking about ideas we had for our project. We agreed it would be cool to have an handheld device that offers control of on-board synthesizers through different gestures, and having the ability to train ML models to map certain gestures to certain synth parameter values. We then went off and did our own research.

I had conversations with Gemini to identify popular and well maintained gyroscope/accelerometer and open source synth libraries before landing on something like the MPU6050 or 9250 for a sensor and the AMY library for an open source synth compatible with the ESP32.

I cross referenced the information that I found with Gemini with the AMY GitHub, different computer engineering forums, and posts on Reddit. I searched for examples of people's uses for AMY.

I found a research paper on NIME that talked about using the gyroscope and accelerometer in a mobile phone tot control a synth, which is pretty similar to what we want to do.


## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

My findings are all located in our moodboard.md file in our group's folder in the 'instruments' repo.
Here is a copy of exactly what I found/thought:

Image of an MPU6050, a sensor with an accelerometer and gyroscope:
https://user-images.githubusercontent.com/107638696/241324971-43b8fe88-447d-4c2d-9296-4b3aaa50f4ce.png
* Should check out the MPU9250 for more axis as well as cleaner data
* https://zbotic.in/imu-sensor-guide-mpu6050-mpu9250-and-bno055-compared/?srsltid=AU7gw4UcXRb2_O0SFwAz78L8INNkb5gx0ugbsdlqXwrWyA89GCbB0bnu

AMY Synth Library, a comprehensive synth library that is optimized for the ESP32:
https://github.com/shorepine/amy

Demonstration of the AMY Synth Libaray:
https://www.youtube.com/watch?v=VHB0kLcmQHg

A paper about SenSynth, an open source mobile application that allows for synth control using accelerometer and gyroscope data:
https://nime.org/proceedings/2012/nime2012_149.pdf

Video demonstration of SenSynth:
https://vimeo.com/97989673?turnstile=1.DEgov8EZq8QDTadoaLfSvU74s2XijkMHu3AmtT7ahDn3-Ui0ntGgkfre9NaC866IBu1lxCIDvwiDdc2yDurbCCWJBIztPQHhzfw9v8kGiVNheK8mAB5W-F0n-NJspl2fvtiCHmzLRSEvYY-0p5H5vY_clqzl3NZmDfAVDgDpagNULwlwZbmG365bbTFjQxuE90qqQFnSBGZdyB6nLvYsH3ICh1k1fjtgSEjV-jksYd0ACuXW6mE0Jx6g0Ag_u94xxWUuPWeyW1gw4UIPvJCksEcjVrrmJSn9T9wAsfCkyib4vqOBEjzVbSPALt-wL79IGw_gVdD2fjsO7WzM6c1ZZYf3T4HD2aBixemG-5dW_AVkohJBX9XHs7BSHiYdIW5glzedDeshU8InDiuJ8zkdj7MuBIAB3sbHqubb_MbuuvCNyk9YvgcWBdC_-uQMPbkxh-X3ndHIUNBlomoiEIF8Ot7bkz26oPEbitBHa2CdW05EUWXtc8KXkn7A9WZ9FaZAwyWViQYyJvZ5nC5-SPQr8SdkBejTiAkLMIvZBEx3dWjXnwxHDCnimviduKhAmUeBRLcHrzxjcR83p6bjP2wtlbKY9jM4IK5hMymu9s1yyQ-wDtM-rgKcDjBIRXpanUib.96gkb-rYDtXxtPHJSumLTw.9c06786a500c2208ba4f4cb9f19ef19ec97409e379cc8ac0947e2ec8341d6e50

Having the device be self contained and have pitch control, or be able to connect it to a MIDI device and control parameters of synth while playing it

Combining slow, smooth gestures to transition between synth parameters with fast programmed gestures to trigger specific sounds. Maybe have gestures that can trigger drum sounds while playing

---

I did find that the MPU9250 offers cleaner data and includes 3 more axis of magnetization than the MPU6050, and isn't much more expensive. It'll be worth exploring what kinds of sensors would be optimal for our project.

Here are my notes for the SenSynth paper:

- Designed to push the boundaries of the complexity with which a mobile phone can control a synthesizer
  - Also designed to be accessible to a wide range of musicians who may not be as familiar with digital instrumentation
- SenSynth provides a GUI to control which sliders and parameters are controlled from - sensors (or from sliders and buttons on the phone for extra parameters)
- The mapping is open ended to accommodate a wide variety of synthesis techniques
- Has a wide variety of sensors to map to different parameters as well as built in synths and effects
  - Sensors: Gyroscope, Accelerometer, Magnetometer, GPS, Compass, Light, Orientation, Proximity, Tap
  - Synths/Effects: Wavetable Synth, Scanning Synth, Granulator, Sampler, Karplus, Delay, Reverb, Pitch Shifter, EQ, Tuner
    - Each sensor, synth, or effect has multiple parameters that can be controlled
- SenSynth also offers magnetic ring control:
  - The magnetic ring is mapped to the phones magnetometer
  - Similar to a Theremin except the user is free to select what they want the ring to control
- Includes a global pitch quantizer to each the playing of musical notes in key

---

## Reflection

**What worked:**

I learned a lot about how gyroscopes, accelerometers and magnetometers work and can be applied to a synth instrument. I also thought of some ways we could possibly differentiate our project form previous similar projects. I know little to nothing about electrical engineering, so it was helpful for me to start getting familiar with how the project design process goes for these types of projects.
* I also got my board to load the starter code which I hadn't managed to do in our previous meeting. I don't have the proximity sensor, I just got the code to load.

**What didn't:**

I could always do more exploring. I still think we could find a way to add an interesting "extra dimension" to our concept, but it is hard to think of something that would naturally integrate into the instrument while still offering a whole new way to interact with the synthesizer. I had a difficult time finding papers or ideas that reached out of the scope of our current ideas that could fit seamlessly with the idea of a controlling a synth through moving our instrument through space.

## Next week

Two or three specific things, each with a date.

- [ Work with my group to figure out parts of the project that each of us could take on 9/20/2026 ]
- [ Complete whatever it is that my group decides on 9/24/2026 ]

## Meeting notes

This meeting we were introduced to the ESP32 and loaded up some basic code/learned how to connect basic proximity sensors to our board. I wasn't able to do much since my dev kit didn't have all the necessary supplies to get the starter code running.
