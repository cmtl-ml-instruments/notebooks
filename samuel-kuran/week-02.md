# Week 2 — Teams, Inspiration, and Boards

**Name: Samuel**
**Credit hours: 2**
**Date: 09/19/26**

---

## Goals

- Discuss the direction of the project with Caleb and Talal
- Get a better understanding of the technology we're working with.

## Methods

- Met with Talal around 7pm at the student center.
  - I asked him some questions about the board and the code to get a better understanding.
  - We also briefly discussed where we could go with the project. I mentioned my star wars project last semester, in which we used accelerometers to add real-time collision effects to the lightsabers.
- I took notes on [Getting Started with Arduino](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/?_gl=1*1r5axoj*_up*MQ..*_ga*MTc1NzYwNjI2LjE3ODk2ODg0ODc.*_ga_NEXN8H46L5*czE3ODk2ODg0ODQkbzEkZzAkdDE3ODk2ODg0ODQkajYwJGwwJGg3ODA4MDk3ODU.), comparing to the sonar code, to understand what every line does.
- Saved links to [Arduino Docs](https://docs.arduino.cc/?_gl=1*s1bj2n*_up*MQ..*_ga*MTE0MzU5MjkwMC4xNzg5ODU3MDM0*_ga_NEXN8H46L5*czE3ODk4NTcwMzIkbzEkZzAkdDE3ODk4NTcwMzIkajYwJGwwJGg2ODE1Mjg3ODQ.) and [Language Reference](https://docs.arduino.cc/language-reference/) for future reference
- Looked at [C++ types](https://en.cppreference.com/cpp/language/types) to understand unsigned integers. Looked at [a C++ style guide](https://google.github.io/styleguide/cppguide.html) to see when to use them. It's a whole controversy. I likely won't use them.

## Results

- Summary of learnings from my notes:
  - Basic components of an arduino (microcontroller, usb port, usb to serial chip, 5V/3.3V pins, GND, etc.) though I struggled to map each one to the ESP-32
  - Basic real time structure using setup(), loop(), and analog/serial signals. This is similar to JUCE and Unity.
  - Serial communication protocols (SPI, I2C, UART): Purpose is to interpret binary, square wave signals. How to send and receive them with `digitalRead()` and `digitalWrite()`
  - Some basic C++ syntax. Most of it looks like java (which I know). Loops, conditionals, include statements, function definitions, ternary statements.
  - The arduino screen seems about 200 pixel wide and 300 pixel long, with the left edge representing (0,0).
  - Used the Serial plotter in tools, which is a great debugger for a real-time program.
  - Basic Arduino API functions (`delay()`, `millis()`, Serial class methods, pin management)

---

## Reflection

**What worked:**
Meeting with my group was motivating.  
**What didn't:**
Need to come prepared to group meetings and to focus on the action items that require discussion. The self-study is something to do on my own.  
**What I'd do differently:**
- Come prepared to both my individual group meeting and the full team meeting.  
- Get notebook submitted before Friday's meeting.  
## Next week

- Priority: Learn about connecting the ESP-32 to wifi and to sound. Have some working scripts to show mastery. Think about possible instruments in the process (by Wednesday 9/23)
- Start learning about the math of ML by consulting Kyle. Have the notes summary in Week 3 notebook by Thursday 9/24
- Attend subgroup meeting with Talal and Caleb scheduled for 7pm at the HIVE. We will be soldering the new parts Kyle gave us. Also come up with a tentative instrument proposal. (Thursday 9/24)

## Meeting notes
- Kyle gave us accelerometer and laser sensor.
- Kyle promised to send me some example scripts for wifi and for sound with ESP-32.
- Connor mentioned Amy synth library, which I should checkout.
