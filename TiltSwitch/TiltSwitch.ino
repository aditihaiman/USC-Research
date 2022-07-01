/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int switchPins[8] = {1, 2, 3, 4, 19, 20, 21, 22};
const int ledPin = LED_BUILTIN;  // the number of the LED pin
const int speaker1 = 8;
const int speaker2 = 9;

//scales
const int cMajor[8] = {262, 294, 330, 349, 392, 440, 494, 523};
const int cMinor[8] = {262, 294, 311, 349, 392, 415, 466, 523};
const int cMinorHarmonic[8] = {262, 294, 311, 349, 392, 415, 494, 523};


const int numSwitches = 8;

// variables will change:
int switchStates[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
//   initialize the pushbutton pin as an input:
  pinMode(speaker1, OUTPUT);
  pinMode(speaker2, OUTPUT);
  
  for(int i = 0; i < numSwitches; i++){
    pinMode(switchPins[i], INPUT_PULLUP);
  }
}

void loop() {
  // read the state of the pushbutton value:

  for(int i = 0; i < numSwitches; i++){
    switchStates[i] = digitalRead(switchPins[i]);
    Serial.print("\tSwitch ");
    Serial.print(i);
    Serial.print(" is: ");
    Serial.print(switchStates[i]);
  }

  Serial.println();

  int tone1 = 0;
  for(int i = 0; i < numSwitches; i++){
    if(switchStates[i] == LOW){
      //if(tone1){
        tone(speaker1, cMinorHarmonic[i]);
        tone1 = 0;
      //}
//      else{
//        tone(speaker2, cMajor[i]);
//        tone1 = 1;
//      }
    }

  }

  delay(100);
}
