# Week 1 — Initial Research (Starting to become familiar with contemporary research relating to ML's usage in musical applications)

*This is your notebook for week 1. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 9/9/2026

---

## Goals

What you set out to do this week.

This week, I set out to read and take notes on, "Fiebrink & Sonami, Reflections on Eight Years of Instrument Creation with Machine Learning (NIME 2020)", a research paper provided by Kyle, and to find my another related research paper to read and take notes on.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

The paper that Kyle gave us: https://www.nime.org/proceedings/2020/nime2020_paper45.pdf (about Wekinator)
The paper that I found to read: https://nime.org/proceedings/2026/nime2026_16.pdf (About IMPSY)

I used Gemini to clarify certain technical details that I did not understand. For example, I read in the second paper that instruments with MIDI out allowed for a more complex interaction between the user and the AI. My initial thought was because you could input the MIDI out messages back into the instrument and allow for a "shared human-AI interaction", so I used Gemini to see whether or not my initial interpretation was correct or if there was some other reason I was missing.

## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

I took notes on what I read and tried to get as much of an understanding of each project as I could so I could learn about what the ML-music interaction looks like. Normally I get bored reading research papers, but I actually found these interesting. I think it's because I was able to relate to the subject matter in a way that I normally can't with standard computer science research paper.


Here are my notes for the first paper (Wekinator):

- Uses Laetitia Sonami's practice as a case study for using ML in instrument building and performance practices
  - What worked well for her, what didn't work well
- How Rebecca Fiebrink (creator of Wekinator) changed her software and teaching practices due to working with Sonami
- Classic ML music training
  - Train a machine learning model on a data set of gestures which map to musical parameters i.e. synth values)
  - These tools typically support an "interactive machine learning" approach where creators can easily refine models by providing new examples to fix mistakes or expand the capabilities of their model
  - The wider the changes made between examples, the more unpredictable the instrument
- Reading this showed me examples of how the collaborative process between two people with different skill sets can help push each other's pursuits when they are each working on two pieces of a larger goal
- It also helped me see how people think about making/improving design choices over time, or how developers can pivot their project to better suit its target audience

My notes for the second paper (IMPSY):

- Generative AI is generally seen as a threat to musicians, so Martin approaches AI music creating from an artist-centered lens
- Intelligent Musical Instrument: An instrument where an AI system generates actions independently of a musician's actions.
- Implementing AI on Raspberry Pis and Bela platforms allows them to be embedded within self-contained musical instruments
- Martin creates a new platform which is affordable and easier to use for non-AI experts, lowering the barrier of entry and inviting creation
- Example: the Intelligent Volca
  - Listens to MIDI signals from the instrument and responds with AI-generated continuations of the performance state
  - The program is able to play notes as well as change parameters of the instrument which is being played
  - MIDI data is saved in timestamped logs so that they can be used as datasets for future training
- Devices with MIDI-in and MIDI-out allow for "two-way human-AI interaction" because they can feed MIDI data back into themselves.
- With Intelligent Setups, Martin noted that he was able go from sparse sounds to walls-of-sound. He was able to adjust the performance of his instrument on the fly
- The IMPSY can also be used to control OSC signals, digital instrument parameters, etc.


---

## Reflection

**What worked:**

For Wekinator:
- Wekinator allows artists to create instruments which give them control over how the sound palette and breadth of possible interactions. It allows gestures to control dozens of parameters resulting in a complexity that would not be possible otherwise.
- But the artist cannot fully control how each gesture will affect the sound, so there is a level of unpredictability when performing. This turns the instrument into sort of a creative partner. The user can give it certain guidelines, but the instrument will then take those guidelines and use them in complex or sometimes unexpected ways.
  - Wekinator offers the ability to "freeze" the sound if an artist really likes it so they can save it and use it for future training or use
 
For IMPSY:
- It allows for ML integration across over any musical medium
  - Lots of flexibility whether it be with MIDI, OSC, controlling digital parameters, etc.
- Since it runs on a Raspberry PI it can be used for embedded musical instruments.
- The web interface allows the user to train and recall models, as well as saving datasets
  - The creator prioritized accessibility, using affordable parts and creating an easy to use user interface. This lowers the barrier to entry and invites more creativity than computer science and technical troubleshooting
- Great for hacking together models quickly to get a desired result


**What didn't:**

For Wekinator:
- Sonami complains about not being able to save a collection of models as an instrument
- She also complains about synthesis being too simplistic for the modern paradigm of ML mapping. She feels limited by the amount of control available on modern synthesizers.

For IMPSY:
- Martin notes that the sweet spot for parameter control is between 1-8. This pales in comparison the number of parameters Sonami controlled with Wekinator (approximately 80).
- For wildly unpredictable and complex synthesis, Martin's IMPSY protocol is not ideal, especially compared to Wekinator
- He also notes that the instrument would benefit from having musicians from different backgrounds play with it to guide future design decisions

## Next week

Two or three specific things, each with a date.

- [ Come up with a few ideas for interesting instruments that could be built 9/17/2026 ]
- [ Read more research papers relating to interpreting dance movement into sound 9/15/2026 ]

## Meeting notes

Our first meeting was very introductory, so not too much to write about. Just worth noting that there are many ways in which we could take this project.
