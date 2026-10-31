# Week 8 — Physical Prototype and Granular Synthesis

**Name: Samuel Kuran**  
**Credit hours: 2**  
**Date: 10/30/2026**  

---

## Goals  

- Group Goal: Print out the CAD Design. Finish starter synthesis patch. Start the ML Patch.- Friday 10/30
  - Personal Goal: Finish the starter synthesis patch.
- Meet with Caleb and Talal at the HIVE - Monday 10/26 7pm
  - Solder STEMMA QT to JST for the 6dof
  - Update weekly goals
  - Discuss wiring instrument

## Methods  

- Cleaned up my granular synthesis patch so that it works on initialization (just committed my changes)
- Refreshed my understanding of granular synthesis using the [Computer Music Tutorial](https://ebookcentral.proquest.com/lib/gatech/detail.action?pq-origsite=primo&docID=30163457).
- Brainstormed the parameter mapping for the granular cloud, and how that would connect to the physical gestures. My friend Hayden Sebastian helped with this too.
- Met with Talal at 7:30pm Thursday 10/29. We tried to get the 6dofs working and updated our weekly goals.
  
## Results  

- I figured out the primary sound parameters: grain duration, grain density, grain bandwidth, and grain center frequency. I put a detailed summary in the [decision points](https://github.com/cmtl-ml-instruments/instruments/blob/main/group-1/Instrument%20Worksheet.md#8-decision-points)
- The granular synthesis patch is much cleaner and more reliable now, but I have yet to implement the new parameter system. I also need the physical modelling.
- Talal and I somewhat got the 6dof working, but it was very buggy.

---

## Reflection  

**What worked:**  
I was most productive when discussing my ideas with other creative people. Solidifying these ideas in the repo is important too to keep everyone on the same page.

**What didn't:**  
We couldn't meet at the HIVE because Caleb was very busy. It did slow our progress somewhat. Caleb was good on communicating this though.

**What I'd do differently:**  
Mainly trying to publish my work to the repo in time for the team meeting.

## Next week  

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

## Meeting notes  

- We need to include some research documentation this coming week. The quality is measured by how replicable our instrument is from the documentation details.
- Caleb has a high quality camera that we can use for research pictures
- Mohan posted his gyroscope code and setup to his notebook.
