#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

struct Button
{
    const uint8_t OptoPin;
    const int Note;
    bool PreviousState;
    bool CurrentState;
    unsigned long LastPushedTime;
};

const int BUTTON_COUNT = 4;
Button cNote = {.OptoPin = 5, .Note = 53, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button dNote = {.OptoPin = 4, .Note = 54, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button eNote = {.OptoPin = 3, .Note = 55, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button fNote = {.OptoPin = 2, .Note = 56, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};

Button buttons[BUTTON_COUNT] = {cNote, dNote, eNote, fNote};

// MIDI SETTINGS
const int VELOCITY = 127;                   //Max Velocity (range is 0-127)
const int CHANNEL = 1;                      //MIDI Channel 1 (out of 16)
unsigned long RESONANCE_TIME_MS = 2 * 1000; // how long a note should ring out naturally after being pressed

#endif
