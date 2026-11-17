# Week 11 — "A Stranger Can Pick It Up and Play It"

**Name:** Samuel Kuran  
**Credit hours:** 2  
**Date:** 11/20/26  

---

## Goals  

- The group goal is clear - a stranger can pick up our instrument and play it. Our instrument needs to be ready for user testing - Friday 11/13
- Intensive subgroup meeting with Caleb and Talal at the Hive - Monday 11/16 7:30pm
  - Finish the wiring, connecting iris script, and max code. Wifi script also needs to get going.
  - Have Caleb take some nice pictures of the instrument
  - Extra: Discuss the name further
- An important secondary goal is to complete the sound of the instrument by giving each grain the sound of a bowed string. Make sure these changes don't jeopardize a functioning product. - Friday 11/13

## Methods  
- Researched the acoustics of string instruments and listened to some of my favorite pieces involving string instruments to try to emulate them in Max.
  - [Violin Acoustics Intro](https://newt.phys.unsw.edu.au/jw/violintro.html)
  - [String example](https://youtu.be/ze0Rk-m0w2A?t=310)
  - [Bow Exciter Heimholtz Cycle](https://newt.phys.unsw.edu.au/jw/Bows.html)
  - [Wave Guide Synthesis of String](https://www.dsprelated.com/freebooks/pasp/Digital_Waveguide_Bowed_String.html) (I needed more understanding to fully grasp this part)
- Met with Caleb and Talal Monday 11/16 7:30pm
  - Made slow progress on the connecting scripts from the instrument to max.

## Results  

- I synthesized a decently convincing bowed-string sound by modifying the Karplus strong algorithm. Analog instrument emulation is something I am passionate about, so this is really great! I used the resources above, and my ear, and played with Karplus strong until I was happy.
  - Note, the upper pitch range of the instrument is limited to midi 77 because of limitations  in the delay time from tapout~. I intend to use sample delays in gen~ to fix this.
- I struggled for a long time just to get Kyle's code working again for iris. We ultimately figured out that the issue was coming from bent pins in the Adafruit feather. I expect that was my fault, so lesson learned to avoid forcing things. Luckily Caleb was able to fix the pins.

---

## Reflection  

**What worked:**  


**What didn't:**  


**What I'd do differently:**  


## Next week  

Two or three specific things, each with a date.  

- [ ]
- [ ]

## Meeting notes  

Anything from class worth keeping.  
