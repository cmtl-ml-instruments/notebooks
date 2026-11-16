# Week 10 — Pre-Prototype

**Name:** Samuel Kuran  
**Credit hours:** 2  
**Date:** 11/12/26  

---

## Goals  

Ideally: our group goal for next week is to have a minimum viable product. With Kyle’s Iris script done, it is totally possible to connect the entire instrument to max. - Friday 11/13
- I’m going to be very busy with this Neo Arcade event for another class, but I’d like to add physical modeling synthesis to the patch and help with the angular acceleration and position calculations. - Friday 11/13
- Meet with subgroup post Neoarcade - Thursday 11/12
  - create a script to get angular acceleration and other values from the 6dofs that we need for the training.

## Methods  

- Met with Caleb and Talal and the HIVE Thursday 11/12 7-8:15pm
  - Worked with Talal on modifying Kyle's script by calculating angular acceleration, and absolute position. (Caleb was wiring the instrument)
- While working on the Neoarcade, I learned about physical modeling synthesis (PhM) through the [computer music tutorial](https://ebookcentral.proquest.com/lib/gatech/detail.action?docID=30163457&pq-origsite=primo). I also implemented a Karplus-Strong algorithm in Pure Data.
- Talked with my friends about possible names for the instrument.

## Results  

- [Karplus Strong Pd Code]<img width="548" height="723" alt="image" src="https://github.com/user-attachments/assets/9da1e8f1-6e16-4aa7-8fe2-3895a5b613a0" />
- [Some pseudo-code for the iris script for Talal](https://github.com/user-attachments/files/34893725/2.sustained.formant.30710a.O.0.55.fate.ng.pdf)
- The most useful thing I learned about PhM synthesis is that these sounds comprise an exciter and a resonator, and their coupled relationship can be simulated with feedback filters. There is so much more to learn, but the math gets complex quickly.
- My tentative name for the instrument is the Granulin (Granular-Violin). My friends liked it. Caleb has doubts. I'm glad he was honest with me.
I found a [book that details the mathematics of music](https://galileo-gatech.primo.exlibrisgroup.com/discovery/fulldisplay?context=L&context=L&vid=01GALI_GIT:GT&vid=01GALI_GIT&docid=cdi_globaltitleindex_catalog_286865516&tab=default_tab&lang=en) which will be very useful to me.


---

## Reflection  

**What worked:**  
Meeting as a subgroup is always productive. Reusing work from other classes has improved efficiency.

**What didn't:**  
We did not get a minimum viable product in class. Ran out of time.

**What I'd do differently:**  
I should have made sure Caleb and I were on the same page with the wiring in the subgroup meeting. We found the ideal wiring after Caleb had already done some soldering. Discussing it earlier would have saved some time.
In general, anticipating gaps in communication is the skill.

## Next week  

- The group goal is clear - a stranger can pick up our instrument and play it. Our instrument needs to be ready for user testing - Friday 11/13
- Intensive subgroup meeting with Caleb and Talal at the Hive - Monday 11/16 7:30pm
  - Finish the wiring, connecting iris script, and max code. Wifi script also needs to get going.
  - Have Caleb take some nice pictures of the instrument
  - Extra: Discuss the name further
- An important secondary goal is to complete the sound of the instrument by giving each grain the sound of a bowed string. Make sure these changes don't jeopardize a functioning product. - Friday 11/13

## Meeting notes  

- It was mostly work time. We are going into the week of the prototype. User testing is going to happen.
- Mohan gave me permission to use his [wifi script](https://github.com/cmtl-ml-instruments/instruments/blob/8f143dd403e80c6f2044346c4dcb23d90ae37dfb/group-2/ESP32-code/firmware/FeatherTransmitter/FeatherTransmitter.ino) to connect the ESP32 feather. He also said to check out the ESPNOW and Feather documentation.
