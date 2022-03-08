
# Midi Accordion Project

## Resources

- http://bvavra.github.io/MIDI_Accordion

## Prototype Progress

### Blink

Goal: Make sure Arduino functions

- Open up the Arduino program
- Select the right board, processor, and port
- Upload it to the board

Success: make sure the light is flashing

### Btn LED

Goal: Make sure we can connect to a sensor

- Get a breadboard
- Connect the Arduino to the power and ground rails
- Connect power rail -> button, button -> 1K ohm resistor, 1K ohm resistor -> ground rail
- Connect signal to arduino based on pin declared in config.h
- Connect ground rail -> short end of LED, long end of LED -> 1k ohm resistor, 1k ohm resistor -> signal line, signal line -> arduino based on pin declared in config.h
- Then program the arduino with the btn_led.ino

Success: Button press turns light on

### Btn MIDI

Goal: Make sure we can play MIDI sounds by pushing a button

- Make sure the MIDI library (Francois Best) 5.0.2 is installed in Arduino
- Install Hairless MIDI serial http://projectgus.github.io/hairless-midiserial/#downloads
- 64 bit version: https://github.com/projectgus/hairless-midiserial/files/4476818/hairless-midiserial.app.64bit.zip from https://github.com/projectgus/hairless-midiserial/issues/51#issuecomment-613583025
- Setup virtual MIDI https://feelyoursound.com/setup-midi-os-x/ & create
- Connect the buttons and LEDs as specified in the config
- Start up the Hairless Midiserial program & set the incoming port to be the Arduino and outgoing to be Midiaccordino Bus
- Open the Virtual MIDI Program --> just to ensure the midiaccordion setup is good. Otherwise it can be closed

Success: Open garageband and press the button. You should now be able to hear a sound.

### Opto

Goal: Make sure we can use opto interrupters as inputs.
Success: Block space between opto-interrupters and hear different midi sounds.

#### Resistance Calculations

Here's the datasheet on the opto-interrupters: https://www.mouser.com/ProductDetail/Everlight/ITR-9608?qs=8cKuZ6Ok2lY35YbtvOHkMw%3D%3D

SO walkthrough: https://arduino.stackexchange.com/questions/76131/how-do-i-know-if-i-need-to-use-a-resistor-in-a-circuit

Important parts:
Forward Voltage (Internal Voltage Drop): 1.2V typical 1.5V max
Forward Current (Max Current) = 50mA = 0.05A

Ohm's Law is: V = IR
Therefore R = V/I
R = (input voltage - forward voltage)/(maxCurrent * limit%)
The arduino will provide 5V.
We want to downgrade the current by 25% so that it lasts longer.
So the final formula is
`R = (5V - 1.5V)/(0.05A * 0.75) = 93.33`
--> we need about 100ohm resistor
100ohm between the power and each side, then a 10K pull down resistor to GND between the emitter & the output wire
