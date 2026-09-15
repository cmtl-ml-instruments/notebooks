# Week 1 — Precedent Research

**Name:** Samuel Kuran
**Credit hours: 2**
**Date: 9/11/26**

---

## Goals

1. Read — [Fiebrink & Sonami, Reflections on Eight Years of Instrument Creation with Machine Learning (NIME 2020).](https://www.nime.org/proceedings/2020/nime2020_paper45.pdf) 
2. Research one more gestural instrument or interface of interest in any era, using any technology.
3. Compare what each instrument does well, and what they do not do well. Note where the papers disagree, if applicable. Critique the research.

## Methods

1. Did not fill out online notebook in time (apologies), but came with notes from the first paper to our second meeting.
2. Read Gwangyu Lee. 2026. iXeRemin: Designing a Polyphonic MR Instrument for Artistic Performance and Interaction. Proceedings of the International Conference on New Interfaces for Musical Expression. DOI: 10.5281/zenodo.20784417 [PDF](http://nime.org/proceedings/2026/nime2026_136.pdf)

## Results

What ML-driven instruments using Wekinator do well
1. Great for learning quickly with complex inputs, such as gestural inputs. Well suited to many-to-many parameter mappings.
2. Good for quickly changing the mapping of multiple parameters, allowing the musician to move through “synthesis terrains” in real time.
3. The instruments themselves are accessible, in that they can be learned by tinkering around.
   
What needs work
1. Transparency: It is hard to understand how the model will react to changes.
2. Synthesis: Synthesis techniques have not caught up to take full advantage of a many-to-many parameter mapping.
    1. This presents an exciting opportunity to explore new synthesis techniques. As a start, I think granular synthesis could work if you let the model control the parameters of each grain using multimodal input. Kyle also mentioned neural networks.
3. Longevity: Issues with models lasting beyond their original use.

iXeRemin is a polyphonic mixed-reality instrument that maps fingertip gestures to musical chords and FM synthesis parameters.
Aside: The instrument uses FM synthesis, and it’s quite fitting how they used the index finger to control the index of modulation!

What it does well
1. Transparency: Real-time visual interface helps performers understand exactly how their gestures impact the system. For example, there are constantly updating data boxes for the parameters near the corresponding fingers, and this data flow switches off when the hand goes outside the boundary box, letting the performer know the sound is muted.
2. Modularity: Can be used as part of something larger via OSC compatibility. Multiple instances can be routed to a host too. Compare this to Wekinator, which still needs features such as model bundling to support this kind of flexibility
3. Real-time parameter customization in the settings window.

What needs work
1. Rigid parameter mapping - each parameter is hard coded.
    1. The FM modulator frequency is fixed at 220Hz, which means user’s cannot the spacing between harmonics
    2. I suspect the voicing of chords is strictly block chords, because each chord is controlled as a unit. This drastically limits the compositional possibilities. They have made strides in the gestural interface, but there is more to do.

Critiques
- The iXeRemin paper uses terminology like midi chord structures and abbreviations without clarifying them first.
---

## Reflection

**What worked:**
Fiebrink and Sonami’s writing was easily understandable, and got me excited to build.

**What didn't:**
It took me a bit to find a NIME paper that interested me and felt relevant.

**What I'd do differently:**
- I’d get my second notebook done before our meeting!

## Next week

- Discuss the direction of the project with Caleb and Talal (By Thursday 9/17)
	- Get their opinions on the kind of instrument
	- Figure out where to start in the process (either learn ML theory with Kyle, start learning the circuitry, or start DSP in Max)
- Take notes from the discussion to use in Week 2 Notebook (9/17)

## Meeting notes

We broke into two subgroups. I’m with Caleb and Talal. I got the basic Arduino patch working.
