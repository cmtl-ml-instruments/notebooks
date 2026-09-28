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
- I met with Talal to discuss the research proposal. 

- I worked with Caleb to try to get the ESP-32 3.5'' backlight working. This is something that we need some help with. The [ESP-32 3.5''](https://www.lcdwiki.com/3.5inch_ESP32-S3_Display) is noticeably different from the [2.8''](https://www.lcdwiki.com/2.8inch_ESP32-S3_Display). For example, the LCD Driver is the ST77922 and the display interface is QSPI compared to the ILI9341V driver and 4-line SPI interface on the 2.8''. This is likely, why the sonar code is not working on the 3.5''. Furthermore, the pin numbering is different. The backlight pins are 41 and 45 on the 3.5'' and 2.8'' respectively.
- I need help finding the ST77922 driver library for the  3.5''. We have the <Adafruit.ILI9341.h> file for the 2.8'', but I couldn't find the right one for the 3.5''. The links below might be helpful for this purpose in addition to the 3.5'' link above.
- [ST7922 Specs](https://dl.espressif.com/AE/esp-iot-solution/ST77922_SPEC_V0.1.pdf)
- [A pin numbering of ST77922 that is consistent with manual](https://github.com/Anda2012/TFT_eSPI_st77922/blob/master/User_Setups/Setup_ST77922_QSPI.h)
- [ST77922 Driver file in a github library](https://github.com/Anda2012/TFT_eSPI_st77922/blob/master/TFT_Drivers/ST77922/ST77922_Defines.h#L8)


## Results

- I learned all of the ESP-32 2.8 inch's capabilities and where they are on the controller. The new ones were the microphone, speaker connection, LED, and general purpose input output (GPIO) pins.
- I learned about all the pins on the ESP-32 and their functions. For example, pin 15 and 16 are the I2C clock and data signals, respectively, which explains why the first was used to trigger the chirp, and the second was used to receive the echo time in the sonar code. These signals also correspond to SCL and SDA of the I2C protocol.
- I got the onboard LED working. It took a good amount of troubleshooting. It required the rgbLedWrite() function from the Arduino > Files > Examples > ESP32 > GPIO > BlinkRGB example. It also required changing the builtin LED pin to 42 per the manual. It's unfortunate that the builtin failed.
- I learned that macros in C++, are textual replacement tools devoid of type checking, and that they should be avoided in most cases, as they can lead to unexpected errors, and they are not faster in today's compilers.
---

## Reflection

**What worked:**  
- Looking at the ESP-32 documentation was crucial to making the LED work. Correct pin numbers should always be checked when troubleshooting.
  
**What didn't:**  
- I could have spent more time on the research proposal.
- I did not get to connect the ESP32 to sound or wifi yet, nor did I learn ML.
- Caleb had to cancel on the HIVE meeting, so we did not solder the accelerometers and gyroscopes.
  
**What I'd do differently:**  
- Being more productive in the early weekdays would give me more time to work on these arduino patches. I need to keep things under control so I can be more timely.

## Next week

- Have a working sound patch before meeting with Talal and Caleb. (9/30)
  - If time, move on to wifi. Also, try AMY.
- Read through the IRIS code and try to understand it. Find extra theoretical sources if needed (9/30)
- Meet with Caleb and Talal at the HIVE for first time (10/1) 

## Meeting notes
- Kyle gave us an intro ML including its roots, the idea of supervised learning, and an example of parameter mapping.
- Talal, Caleb, and I made Thursday 7pm at the HIVE our weekly subgroup meeting time to prep for Friday.
