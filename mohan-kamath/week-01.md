# Week N — title

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Mohan Kamath
**Credit hours: 2**
**Date: 9/11/2026**

---

## Goals

What you set out to do this week.

Read Fiebrink & Sonami (NIME 2020) regarding long-term instrument design with machine learning.
Find and review a second gestural instrument paper: Overholt & Gelineck (NIME 2014) on an accessible hybrid violin platform.
Analyze what each system does well and poorly, followed by a comparative synthesis examining where the systems diverge in their philosophy of what an instrument should be.

## Methods

Read Reflections on Eight Years of Instrument Creation with Machine Learning (Fiebrink & Sonami, NIME 2020).
Read Design & Evaluation of an Accessible Hybrid Violin Platform (Overholt & Gelineck, NIME 2014).
Consulted an LLM assistant (Gemini) to help compare the two design architectures and simplify papers.

## Results

### System 1: The Spring Spyre (Fiebrink & Sonami, 2020)
- What it does well:
  - Exploration of Non-Linear Timbral Spaces: Replaces rigid one-to-one mapping with Wekinator's multi-layer perceptron neural networks, giving access to rich, dynamic "synthesis terrains".
  - Tunable Predictability Index: Sonami can scale performance interaction from tightly controlled behaviors to wide, emergent acoustic responses simply through training data selection.
  - Real-time Performance Intervention: Uses tactile hardware controls to "freeze" specific feature sets in Max/MSP, letting the performer zoom in and improvise over specific acoustic sweet spots.
- What it doesn't do well / Limitations:
  - Synthesis Engine Bottleneck: Modern synthesis models are fragile and struggle to take full advantage of high-dimensional, simultaneously fluctuating parameter spaces without blowing up.
  - Ecosystem Portability: Wekinator historically lacked the ability to easily bundle trained networks into portable modular "instrument units" to move across pieces.
  - Reproducibility of Specific Gestures: It deliberately rejects standard ergonomic determinism; you cannot readily score or replicate precise pitch/gesture sequences.
### System 2: Accessible Hybrid Violin 
- What it does well:
  - Accessibility & Low Barrier to Entry: Built from off-the-shelf, low-cost parts (budget electric violin, iPod Touch, MobMuPlat/Pure Data, Class-T amplifier) with zero destructive modifications to the frame.
  - Unmodified Bow Interaction: Leaves the bow completely unweighted and un-sensored, preserving the violinist's physical muscle memory and acoustic tactile feedback.
  - Self-Contained Portability: Eliminates umbilical tethering to laptops by mounting the DSP, IMU sensing, battery, and BMR speakers directly to the body/performer.
- What it doesn't do well / Limitations:
  - Ergonomics & Physical Fatigue: Placing the mobile device on the performer's forearm caused noticeable fatigue during extended playing.
  - Acoustic Localization / Speaker Placement: Onboard BMR drivers directed sound straight into the player's left ear, distorting loudness perception and physically obstructing bowing near the bridge.
  - Shallow Parameter Mappings: Evaluated mappings relied heavily on basic 1-to-1 linear tilt-angle controls (e.g., tilt angle directly mapped to wah/delay), which the classical performers found uninspiring for sustained expressive depth.

Compare and Constrast:

## Core Philosophy:
- Sonami:
An instrument is an autonomous conversational partner with its own agency.  
- Hybrid Violin Platform:
An instrument is an augmented acoustic tool providing deterministic extensions.
## Mapping Strategy
- Sonami:
Many-to-many, non-linear machine learning regressions via interactive ML.
- Hybrid Violin Platform:
Direct one-to-one / continuous sensor-to-parameter DSP couplings.  
## Control Priority
- Sonami:
Exploration, surprise, and navigating semi-chaotic physical states.  
- Hybrid Violin Platform:
Ergonomic preservation, repeatability, and player familiarity.  
## Repertoire Scope
- Sonami:
Idiomatic and bespoke; a piece and its trained mapping are inseparable.  
- Hybrid Violin Platform:
Generalizable platform intended to support traditional score repertoire and string quartets.

For Overholt & Gelineck, an instrument should serve as a transparent, repeatable extension of the performer’s existing virtuosity. Its expressivity is measured by how seamlessly traditional bowed-string technique can modulate effects without breaking the performer's established physical model.  Conversely, Sonami views the instrument not as a neutral controller to be commanded, but as an active, partially chaotic system that pushes back. By intentionally building physical unpredictability into the springs and using ML to discover non-linear sonic landscapes, the Spyre rejects deterministic predictability in favor of improvisation, active listening, and relational dialogue.

---

## Reflection

**What worked:**

Synthesizing both papers around their mapping differences made the differences between DSP and interactive ML clear.

**What didn't:**

Summarizing Sonami's 8 year workflow into a short breakdown without losing the nuance of her philosophy.

**What I'd do differently:**

Look closer into how modern embedded platforms (like Bela or Teensy) could run Wekinator regression models locally to eliminate the laptop bridge entirely.

## Next week

Two or three specific things, each with a date.

- [ ]
- [ ]

## Meeting notes

Anything from class worth keeping.
