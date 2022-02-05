#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

struct Button {
    const uint8_t ButtonPin;
    const uint8_t LedPin;
    const int Note;
    bool PreviousState;
    bool CurrentState;
};

Button red = { .ButtonPin = 5, .LedPin = 13, .Note = 53, .PreviousState = 0, .CurrentState = 0 };
Button yellow = { .ButtonPin = 4, .LedPin = 12, .Note = 54, .PreviousState = 0, .CurrentState = 0 };
Button green = { .ButtonPin = 3, .LedPin = 11, .Note = 55, .PreviousState = 0, .CurrentState = 0 };
Button blue = { .ButtonPin = 2, .LedPin = 10, .Note = 56, .PreviousState = 0, .CurrentState = 0 };

Button buttons[4] = {red, yellow, green, blue};

// MIDI SETTINGS
const int VELOCITY = 127; //Max Velocity (range is 0-127)
const int CHANNEL = 1; //MIDI Channel 1 (out of 16)

#endif
