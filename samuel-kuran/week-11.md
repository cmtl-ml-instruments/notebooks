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
  - [Wave Guide Synthesis of String](https://www.dsprelated.com/freebooks/pasp/Digital_Waveguide_Bowed_String.html) (I needed more understanding to fullygrasp this part)
  - [Violin Vibrato Playing Guide](https://www.diorviolin.com/post/the-complete-guide-to-violin-vibrato)
- Met with Caleb and Talal Monday 11/16 7:30pm
  - Made slow progress on the connecting scripts from the instrument to max.
- Met with Caleb and Talal Tuesday 11/17 7:30pm
  - Got sound out of max triggered by instrument, but lacking in physical control. Started to debug the arduino script.
  - Had Talal start on a script for sending and receiving data from both gyroscopes using the multiplexer.
- Met with Caleb and Talal Wednesday 11/18 6:30pm
  - Continued debugging arduino script. Made debug functions and made code more modular.
- Meeting Thursday 11/19 7:30pm
  - Attempted to fix the position errors in our code. Narrowed the issue down to velocity drift and g-force problems. Attempted to calculate orientation.

## Results  

- I synthesized a decently convincing bowed-string sound by modifying the Karplus strong algorithm. Analog instrument emulation is something I am passionate about, so this is really great! I used the resources above, and my ear, and played with Karplus strong until I was happy.
  - Note, the upper pitch range of the instrument is limited to midi 77 because of limitations  in the delay time from tapout~. I intend to use sample delays in gen~ to fix this.
- I added the bowed-string sound as the grain-generator.
  - Another issue with the sound, is that there is popping when a grain is given a new pitch before it finished the last. I struggled to create a retrigger algorithm that ramps to 0 before ramping back up. The use of a wavetable for the envelope complicates things. Another thing to return to.
- I struggled for a long time just to get Kyle's code working again for iris. We ultimately figured out that the issue was coming from bent pins in the Adafruit feather. I expect that was my fault, so lesson learned to avoid forcing things. Luckily Caleb was able to fix the pins.
- We are not getting any data out of the gyroscope on the end. We verified the gyroscope is working, so the sender/receiver code has a bug.
- The position is not tracking appropriately. It keeps ticking upward without bound.
  - The acceleration of the imu is measured with respect to free-fall. By plotting the values with the imu at rest, we saw that each coordinate of the acceleration vector had a nonzero offset, which depended on the angle between the vector and the vertical direction. Calculating the change in these angles using angular velocity was complex. I would need more time.
- Instrument is fully connected though!

---

## Reflection  

**What worked:**  
We all miraculously have lots of time this week, so we could meet regularly.

**What didn't:**  
The compiler on Arduino takes forever to compile, which can really slow progress when I am still learning C++, and tend to make simple syntax errors. Something I can do is compiling more frequently.

**What I'd do differently:**  
We almost broke the instrument before the meeting because I was trying to figure out the position. Something I am trying to learn is properly scaling my modifications to the timeframe.

## Next week  

Two or three specific things, each with a date.  

Caleb and Talal will be out for the break, so progress will be limited.
- - Priority is working code and sturdy model. Take notes on the absolute orientation compass. Smooth out data from the other values. Add more poses. - 11/27
- Stretch: Add gen~ delay and retrigger envelope to the sound patch - 11/27

## Meeting notes  

- We bought the absolute orientation compass to avoid further issues with the position calculation. There still is an issue with the position value slowly drifting away over time, perhaps due to a nonzero velocity value that results from numerical errors. Kyle will look at our code regarding this.
- We have to make a video demo of the instrument and have the instrument ready for user testing by December 4.
- We discussed user-testing questions and how they can relate to our research question
