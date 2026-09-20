# Week 2 — Teams, Inspiration, and Boards

**Name: Samuel**
**Credit hours: 2**
**Date: 09/19/26**

---

## Goals

What you set out to do this week.
- Discuss the direction of the project with Caleb and Talal
- Get a better understanding of the technology we're working with.

## Methods

- Met with Talal around 7pm at the student center.
  - I asked him some questions about the board and the code to get a better understanding.
  - We also briefly discussed where we could go with the project. I mentioned my star wars performance last semester, in which we used accelerometers to add real-time collision effects to the lightsabers.
- I took notes on [Getting Started with Arduino](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/?_gl=1*1r5axoj*_up*MQ..*_ga*MTc1NzYwNjI2LjE3ODk2ODg0ODc.*_ga_NEXN8H46L5*czE3ODk2ODg0ODQkbzEkZzAkdDE3ODk2ODg0ODQkajYwJGwwJGg3ODA4MDk3ODU.), comparing to the sonar code, to understand what every line does.


## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

- Summary of learnings from my notes:
  - Basic components of an arduino (microcontroller, usb port, usb to serial chip, 5V/3.3V pins, GND, etc.) though I struggled to map each one to the ESP-32
  - Basic real time structure using setup(), loop(), and analog/serial signals. This is similar to JUCE and Unity.
  - Serial communication protocols (SPI, I2C, UART): Purpose is to interpret binary, square wave signals. Code sends them using digitalWrite(PINNAME, status). With status set to HIGH or LOW
  - Some basic C++ syntax. Most of it looks like java. Loops, conditionals, include statements, function definitions, ternary statements.
  - The arduino screen seems about 200 pixel wide and 300 pixel long, with the left edge representing (0,0).
  - Used the Serial plotter in tools, which is a great debugger for a real-time program.
  - Basic Arduino API functions (delay(), 

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
