#include "config.h"

// GLOBAL
bool optoState = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(OPTO_PIN, INPUT);
}

void loop()
{
    optoState = digitalRead(OPTO_PIN);

    if (optoState == HIGH)
    {
        // accordion button is pressed and blocker bar is lifted
        Serial.println("OPTO HIGH +++++++");
    }
    else
    {
        // accordion button is released and blocker bar is lowered
        Serial.println("OPTO LOW -------");
    }
}
