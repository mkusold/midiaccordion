#include "config.h"

// GLOBAL
bool buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
 buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {            //check if the pushbutton is pressed
    //if it is, the buttonState is HIGH
    digitalWrite(LED_PIN, HIGH);         //turn LED on    
    Serial.println("LED ON +++++++"); 
  }
  else {
    digitalWrite(LED_PIN, LOW);          // turn LED off
    Serial.println("LED OFF -------");
  }
}
