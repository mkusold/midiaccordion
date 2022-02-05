#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

#include "config.h"

struct MySettings : public midi::DefaultSettings
{
  //By default, the Arduino MIDI Library tries to be smart by
  //excluding the CC byte if it doesn't change (to save bandwidth).
  //This is a problem when starting up Serial<->MIDI software
  //after starting up the Arduino because we miss the first CC byte.
  //Setting UseRunningStatus to false removes this "feature."
  //See https://github.com/projectgus/hairless-midiserial/issues/16 for details.
  static const bool UseRunningStatus = false;
  // Set MIDI baud rate. MIDI has a default baud rate of 31250,
  // but we're setting our baud rate higher in order to
  // properly decode and read outgoing MIDI data on the computer.
  static const long BaudRate = 115200;
};

MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MySettings);

void setup()
{
  MIDI.begin();

  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    pinMode(buttons[i].OptoPin, INPUT);
  }

  // clear all off to start to ensure the instrument is silent
  // in case it was put in a bad state on previous exit
  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    MIDI.sendNoteOff(0, 0, CHANNEL);
  }
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    buttons[i].CurrentState = digitalRead(buttons[i].OptoPin);
    const bool isNoteJustPushed = midiLogic(buttons[i].CurrentState, buttons[i].PreviousState, buttons[i].Note);
    if (isNoteJustPushed)
    {
      buttons[i].LastPushedTime = millis();
    }
    handleResonance(buttons[i].CurrentState, buttons[i].Note, buttons[i].LastPushedTime);
    buttons[i].PreviousState = buttons[i].CurrentState;
  }
}

// returns whether a note was initiated or not
bool midiLogic(bool buttonState, bool previousButtonState, int note)
{
  if (buttonState == HIGH)
  {
    // play a note if it's not already playing
    if (previousButtonState != HIGH)
    {
      MIDI.sendNoteOn(note, VELOCITY, CHANNEL);
      return true;
    }
  }
  else
  {
    // stop playing the note if it's still playing
    if (previousButtonState == HIGH)
    {
      MIDI.sendNoteOff(note, VELOCITY, CHANNEL);
    }
  }
  return false;
}

void handleResonance(bool buttonState, int note, unsigned long lastPushedTime)
{
  // if the note has been playing too long, turn it off
  // so it doesn't indefinitely gurgle in the background
  if (buttonState == HIGH && (millis() - lastPushedTime) > RESONANCE_TIME_MS)
  {
    MIDI.sendNoteOff(note, VELOCITY, CHANNEL);
  }
}
