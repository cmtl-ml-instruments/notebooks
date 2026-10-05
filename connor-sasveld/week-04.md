# Week 1 — Exploring AMY on the ESP32 (Figuring out how to get the software to run and output audio)

*This is your notebook for week 4. Click the pencil icon to edit it, fill it
in, and commit. Plain sentences under the headings are fine — you do not need
to know any formatting.*

**Name:** Connor Sasveld
**Credit hours:** 1
**Date:** 10/5/2026

---

## Goals

What you set out to do this week.

This week I set out to get AMY running on the ESP32, just outputting basic audio.

## Methods

What you actually did. Link everything you used — papers, videos, repositories,
documentation, parts. If you used an AI assistant at any point, say so and say
what you asked it. That is information, not a confession.

I have never learned C++, and I don't know anything about the AMY library or how embedded systems work, so I used Gemini pretty extensively to help me figure out how to make things work. I would ask it how to structure the logic of taking in a MIDI input, starting the AMY synth up, processing the MIDI information, and outputting audio. I would then ask lots of follow up questions about the syntax of the code blocks it gave me and how they work, which are included in my script. I would then compile the code and try to fix most of the logic errors that I could by myself, but sometimes I would get an error because Gemini tried using functions that don't exist, and so then I'd ask it to reference the documentation of whatever library that was being used and explain what function should be used to achieve the desired result.

## Results

I didn't have much time to work on my goals since I had midterms and also left for NYC on Thursday. I also had trouble with the USB cable I brought with me on my trip and my computer was struggling to connect with the ESP.

All of that to say, I did not get audio output this week. But I did get a good start on it, and I have a much better understanding of how the logic flow works in the Arduino IDE for this type of application.

Here is the code I ended up with:
#include <Arduino.h>
#include <USB.h>
#include <USBMIDI.h>
#include <AMY-Arduino.h>

USBMIDI USBSerialMIDI;

const int I2S_BCLK = 5;
const int I2S_LRC = 7;
const int I2S_DOUT = 8;
const int AP_ENABLE = 1;

int current_voice = 0;
const int MAX_VOICES = 12;

void setup() {
  Serial.begin(115200);

  pinMode(AP_ENABLE, OUTPUT); //Tells pin 1 to send electricity out to control amp power switch
  
  digitalWrite(AP_ENABLE, LOW); //Sets Amp power enabler to low, wakes up audio amplifier

  amy_config_t amy_config = amy_default_config();

  //Configure AMY synth engine using our pin constants
  amy_config.i2s_bclk = I2S_BCLK;
  amy_config.i2s_lrc = I2S_LRC;
  amy_config.i2s_dout = I2S_DOUT;
  amy_config.features.startup_bleep = 1; //Plays audio bleep on speaker at boot

  //Start the audio thread engine
  amy_start(amy_config);

  char patch_msg[32]; //Empty 32 character text array
  
  snprintf(patch_msg, sizeof(patch_msg), "v0,%dc1K160Z", MAX_VOICES - 1);
    //snprintf creates a string and saves it to a character array
      //snprintf(destination buffer, maximum size, fstring, variables for fstring)
    //v0,%dc1K160Z
      //v0,1%d: voices 1 to MAX_VOICES - 1 (11)
      //c1: Tells AMY we want to configure or copy an instrument profile onto these voices
      //K160 (Patch Key 160): Selects specific sound, 160 is a built-in electric piano
      //Z: End of message 
      
  amy_add_message(patch_msg);

  USBSerialMIDI.begin();
  USB.begin();

  Serial.println("ESP32-S3 Synth Live");
}


void loop() {
  midiEventPacket_t rxPacket; //Creates an empty MIDI message packet

  if (USBSerialMIDI.readPacket(&rxPacket)) { //readPacket() returns a bool [whether or not the message is valid], the "&" qualifier specifies that we are passing in the actual memory location of rxPacket, so the function will modify that memory location rather than a copy of the value
    uint8_t status = rxPacket.byte1; //byte1 is the MIDI status which contains the command and channel
    uint8_t command = status & 0xF0; //What action just happened, &0xF0 filters out the MIDI channel number so it only looks at the action command
    uint8_t note = rxPacket.byte2; //byte2 of a MIDI message eis the note
    uint8_t velocity = rxPacket.byte3; //byte3 of a MIDI message is the velocity
    //uint_8 is an unsigned (non-negative) 8-bit integer
    
    char amy_cmd[32];
    //0x90 is the Note On command
    if (command == 0x90 && velocity > 0) {
      float amp = (float)velocity / 127.0; //Scales velocity (0-127) to AMY linear amplitude (0.0-1.0)

      snprintf(amy_cmd, sizeof(amy_cmd), "v%dn%dl%0.2fZ", current_voice, note, amp);
        //v%d: Voice slot
        //n%d: Note Pitch
        //l%0.2f: Volume (lowercase l stands for Linear Amplitude), %0.2f stands for a floating point number with two decimcal places
        //Z: Execute message
      amy_add_message(amy_cmd);

      Serial.println(amy_cmd);

      current_voice++;
      if (current_voice >= MAX_VOICES) {
        current_voice = 0;
      }
    }

    //0x80 is the Note Off command (a velocity of 0 also means Note Off)
    else if (command == 0x80 || (command == 0x90 && velocity == 0)) {
      for (int v = 0; v < MAX_VOICES; v++) {
        snprintf(amy_cmd, sizeof(amy_cmd), "v%dn%d10Z", v, note);
        amy_add_message(amy_cmd);
        //Sends a message to every voice to turn off the note that has been released, but since only one voice can be playing any note at a given time, only 
      }
    }
  }
}

---

## Reflection

**What worked:**
I think the structure of having a detailed conversation with Gemini about the details of how two format the logic and syntax of this starter code was very helpful for me learning how to code for embedded systems in C++. It was actually really helpful when it would give me functions that didn't exist because I had to question it and once it found the correct function I was able to deeply understand how it is supposed to work. I think that once I get a better cable, I will be able to quickly get sound out of my ESP32.

(I'm pretty sure it's the cable because I've had problems with it for other applications)


**What didn't:**
I wasn't actually able to get sound out of my board, but, again, I think with a better cable that problem will be solved.

## Next week

Two or three specific things, each with a date.

- [ Actually get audio coming out of the board 10/6/2026 ]
- [ Explore the different synths and their respective parameters 10/8/2026 ]

## Meeting notes

My group got to finalize our initial goals for our instrument, which are obviously subject to change. And we now have a stronger foundation for our progress post-fall break.
