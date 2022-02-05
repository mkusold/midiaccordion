#include "config.h"

// GLOBAL
bool buttonState = 0;
int val = -1; // variable to store the analog value coming from the sensor

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(OPTO_PIN);

    Serial.print("Value for analog PIN: ");
    Serial.println(val);
}
