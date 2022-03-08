#include "config.h"

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    pinMode(buttons[i].OptoPin, INPUT);
  }
}

void loop()
{
  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    buttons[i].CurrentState = digitalRead(buttons[i].OptoPin);
    debug(buttons[i].CurrentState, buttons[i].OptoPin);
  }
}

void debug(bool optoState, int pinNo)
{
  if (optoState == HIGH)
  {
    // accordion button is pressed and blocker bar is lifted
    //Serial.print("OPTO HIGH");
    //Serial.println(pinNo);
  }
  else
  {
    // accordion button is released and blocker bar is lowered
    Serial.print("OPTO LOW");
    Serial.println(pinNo);
  }
}
