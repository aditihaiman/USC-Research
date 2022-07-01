/* Analog Input Example, Teensyduino Tutorial #4
   http://www.pjrc.com/teensy/tutorial4.html

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
*/


/*
 * Connect outer two POT pins to 5v and ground. Middle pin goes to Analog read pin 0 (pin 14)
 * 
 * 
 * Connect speaker to ground and pin 9
 * 
 */
int notes[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523};
String notes1[] = {"C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B", "C"};

void setup()
{
  Serial.begin(38400);

}

int val;

void loop()
{
  val = analogRead(0);
  Serial.print("analog 0 is: ");
  Serial.print(val);
  Serial.print(" , ");
  Serial.print(notes[val/85]);
  Serial.print(" , ");
//  Serial.print(notes1);
  Serial.println(notes1[val/85]);
  tone(9, notes[val/85]);
  delay(500);
}
