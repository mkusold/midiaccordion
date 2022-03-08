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

const int BUTTON_COUNT = 7;
Button c4 = {.OptoPin = 2, .Note = 60, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button c4Shp = {.OptoPin = 3, .Note = 61, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button d4 = {.OptoPin = 4, .Note = 62, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button d4Shp = {.OptoPin = 5, .Note = 63, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button e4Shp = {.OptoPin = 6, .Note = 64, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button f4 = {.OptoPin = 7, .Note = 65, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};
Button f4Shp = {.OptoPin = 8, .Note = 66, .PreviousState = 0, .CurrentState = 0, .LastPushedTime = 0};

Button buttons[BUTTON_COUNT] = {c4, c4Shp, d4, d4Shp, e4Shp, f4, f4Shp};

// MIDI SETTINGS
const int VELOCITY = 127;                   //Max Velocity (range is 0-127)
const int CHANNEL = 1;                      //MIDI Channel 1 (out of 16)
unsigned long RESONANCE_TIME_MS = 2 * 1000; // how long a note should ring out naturally after being pressed

#endif
