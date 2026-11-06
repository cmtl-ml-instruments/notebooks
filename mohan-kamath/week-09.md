# Week 9 — Wireless Tilt-to-C4

**Name:** Mohan Kamath
**Credit hours:** 2  
**Date:** November 6, 2026

## Goals

I planned to turn the smaller ESP32 Feather's motion into one reliable C4 note event and make the source easier to navigate.

## Methods

I used Arduino CLI to flash the temporary ESP32-S3 receiver, then
recorded its USB note events while tilting the sensor and unplugging the Feather.

The receiver arms near level, starts C4 at +22°, and releases at +12°. After the
first motion test, I added a 100 ms hold at each threshold to filter brief
crossings. Link loss still clears the note after 500 ms without fresh data.

I asked OpenAI Codex to reorganize the source. The cleanup gave the sketches clearer names and made it easier to navigate and understand.

## Results

The receiver got about 102–103 packets per second. During the first test,
unplugging the Feather while C4 was active released the note. After restart,
the receiver reconnected and re-armed at level with the note off. Movement
initially caused extra note transitions. With the 100 ms hold, the next capture
showed three tilt-and-return cycles with one note-on and one note-off each.

## Reflection

**What worked:** USB event logs let me separate sensor, wireless, and note
behavior. Holding a tilt and then unplugging the Feather made the release
behavior easy to verify.
**What didn't:** The first version reacted to brief changes in roll while I
repositioned the sensor, which produced extra note events.
**What I'd do differently:** Test slow tilts, quick movements, and link loss
before connecting the gesture to sound. I would keep those checks as a short
bench routine for future changes.

## Next week

- [ ] **November 9:** Route the wireless C4 events to the instrument's synth.
- [ ] **November 12:** Verify audible note release on tilt return and link loss.

## Meeting notes
