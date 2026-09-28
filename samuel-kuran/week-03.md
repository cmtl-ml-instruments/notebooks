# Week 3 — Project Proposal and Putting Tools Together

**Name: Samuel Kuran**  
**Credit hours: 2**  
**Date: 09/24/26**  

---

## Goals

- Priority: Learn about connecting the ESP-32 to wifi and to sound. Have some working scripts to show mastery. Think about possible instruments in the process (by Wednesday 9/23)
- Start learning about the math of ML by consulting Kyle. Have the notes summary in Week 3 notebook by Thursday 9/24
- Attend subgroup meeting with Talal and Caleb scheduled for 7pm at the HIVE. We will be soldering the new parts Kyle gave us. Also come up with a tentative instrument proposal. (Thursday 9/24)

## Methods

- I started by taking notes on the [2.8'' ESP-32 Documentation](https://www.lcdwiki.com/2.8inch_ESP32-S3_Display) from the resources page. Also looked at the [user manual](https://www.lcdwiki.com/res/ES3C28P/2.8inch_IPS_ESP32-S3_ES3C28P_ES3N28P_User_Manual.pdf), which went more in depth with the SPI protocol, and included circuit schematics
- I looked at other sites to understand the difference between bus data, and bus clock signals.
  - https://www.numberanalytics.com/blog/ultimate-guide-clock-circuits-microcontrollers
  - https://www.geeksforgeeks.org/computer-organization-architecture/what-is-a-computer-bus/
- I browsed [forums](https://forum.arduino.cc/t/esp32-s3-onboard-rgb-led/1198754/13?page=2) to try to get the ESP-32 onboard LED working
- I looked at these sites to understand macros in C++ and why good practice is to avoid them in most cases.
  - https://hackaday.com/2015/10/16/code-craft-when-define-is-considered-harmful/
  - https://forum.arduino.cc/t/macro-vs-const/91315/13
 

- I worked with Caleb to try to get the ESP-32 3.5'' backlight working. This is something that we need some help with. The [ESP-32 3.5''](https://www.lcdwiki.com/3.5inch_ESP32-S3_Display) is noticeably different from the [2.8''](https://www.lcdwiki.com/2.8inch_ESP32-S3_Display). For example, the LCD Driver is the ST77922 and the display interface is QSPI compared to the ILI9341V driver and 4-line SPI interface on the 2.8''. This is likely, why the sonar code is not working on the 3.5''. Furthermore, the pin numbering is different. The backlight pins are 41 and 45 on the 3.5'' and 2.8'' respectively.
- I need help finding the ST77922 driver library for the  3.5''. We have the <Adafruit.ILI9341.h> file for the 2.8'', but I couldn't find the right one for the 3.5''. The links below might be helpful for this purpose in addition to the 3.5'' link above.
- [ST7922 Specs](https://dl.espressif.com/AE/esp-iot-solution/ST77922_SPEC_V0.1.pdf)
- [A pin numbering of ST77922 that is consistent with manual](https://github.com/Anda2012/TFT_eSPI_st77922/blob/master/User_Setups/Setup_ST77922_QSPI.h)
- [ST77922 Driver file in a github library](https://github.com/Anda2012/TFT_eSPI_st77922/blob/master/TFT_Drivers/ST77922/ST77922_Defines.h#L8)


## Results

What came of it. Include the things that did not work; a negative result you
can describe is worth more than a success you cannot explain.

- 
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
