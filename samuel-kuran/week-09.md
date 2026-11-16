# Week 9 — Cloud Parameters and Research Documentation

**Name:** Samuel Kuran  
**Credit hours:** 2  
**Date:** 11/06/2026  

---

## Goals  

- Group Goal: (tentative) We wire the instrument. Starting the IRIS patch- Friday 11/6
- Personal Goal: Finish the granular synthesis patch. At a minimum, the cloud controls should be there. More impressive would be the physical modelling part.
  - Stretch: Look at the movements of ribbon dancers and baton throwers for inspiration on movement controls.
- Subgroup Meeting at the HIVE Monday 11/2 7pm
  - Solder STEMMA QT to JST for the 6dof
  - Reach alignment on the physical and sound parameter mappings
  - Discuss ordering an absolute orientation compass. Look in the HIVE. Likely split the costs.
  - Update group and individual goals
  - Discuss research documentation. Mainly, we need a few high quality pictures.
  - Stretch: Name our instrument


## Methods  
- Met with Caleb and Talal at the HIVE Monday 7:30-8:15.
  - We discussed that allowing the performer to switch hands in performance, while ideal, is not possible if we put buttons on the glove.
  - We soldered one of the 6-degrees-of-freedom gyroscopes (6dofs) to its secondary address.
  - We discussed whether or not we should buy an absolute orientation compass. We did not.
- Talal and I talked separately about the iris integration within the project.

## Results  

- I successfully modified the granular synth to take duration, density, bandwidth, and pitch as inputs to the cloud generator. The grain generator was changed from sampling synthesis to a sine-wave placeholder.
- In our meeting, Talal and I realized that my [suggested mapping](https://github.com/cmtl-ml-instruments/instruments/blob/main/group-1/Instrument%20Worksheet.md#8-decision-points) of physical parameters to grain parameters was one-to-one. So, we struggled to justify the use of iris. However, at the Friday meeting, Kyle encouraged us to explore the differences that result from using ML in the mapping compared to hard-coding it.
- Talal and I touched on the idea of including uniformity in the sound of the instrument. That is, when we have multiple parts spinning in different directions, we want that to sound different compared to when those parts are spinning in a uniform way. This could be implemented by making each gyroscope besides the handle control its own granular stream, (its angular velocity and acceleration control the grain density and bandwidth, respectively). Another way would be to have the signal from one stream modulate another stream in some way. The prototype will only have two gyroscopes--one on the handle, and one on the end. But I will keep this in mind for the future.
---

## Reflection  

**What worked:**  
Working through our problems with iris as a group, including asking for Kyle's input was productive. Meeting on Monday is always effective.

**What didn't:**  
The subgroup meeting was too short to cover everything. We were busy.

**What I'd do differently:**  
Should have given Caleb the multiplexer after our subgroup meeting, so he could consider it in the wiring.

## Next week  

Ideally: our group goal for next week is to have a minimum viable product. With Kyle’s Iris script done, it is totally possible to connect the entire instrument to max. - Friday 11/13
- I’m going to be very busy with this Neo Arcade event for another class, but I’d like to add physical modeling synthesis to the patch and help with the angular acceleration and position calculations. - Friday 11/13
- Meet with subgroup post Neoarcade - Thursday 11/12
  - create a script to get angular acceleration and other values from the 6dofs that we need for the training.

## Meeting notes  

- Kyle gave us a great starter code to connect Iris to our instrument. It already works!
- I demoed my new granular sound. It was very interesting, but more ghostly than I intended.
- The degree values of the gyroscope are modded according to Kyle. So 360 will jump to 0. We need to have a procedure to deal with that when mapping angular velocity.

