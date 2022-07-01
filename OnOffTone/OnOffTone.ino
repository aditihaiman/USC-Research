/* Pushbutton with Pullup, Teensyduino Tutorial #3
   http://www.pjrc.com/teensy/tutorial3.html

   This example code is in the public domain.
*/
#include "pitches.h"

void setup() {
  Serial.begin(38400);
  pinMode(8, INPUT);
}

void loop()
{
  if (digitalRead(8) == HIGH) {
    Serial.println("Button is not pressed...");
    tone(9, NOTE_A4);

    
  } else {
    Serial.println("Button pressed!!!");
  }
  delay(250);
}
