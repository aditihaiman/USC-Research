#include <Bounce2.h>
#include <math.h>


// constants won't change. They're used here to set pin numbers:
const int switchPins[8] = {14, 15, 16, 17, 22, 21, 20, 19};
const int ledPinRed = 9;  // the number of the LED pin
const int ledPinGreen = 10;
const int ledPinBlue = 11;
const int speaker1 = 8;
const int speaker2 = 19;
Bounce bounce[8];

//scales
const int cMajor[8] = {262, 294, 330, 349, 392, 440, 494, 523};
const int cMinor[8] = {262, 294, 311, 349, 392, 415, 466, 523};
const int cMinorHarmonic[8] = {262, 294, 311, 349, 392, 415, 494, 523};


const int numSwitches = 8;


// variables will change:
int switchStates[8] = {1, 1, 1, 1, 1, 1, 1, 1};


void setup() {
  // initialize the RGB LED pin as an output:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  Serial.begin(9600);
  pinMode(speaker1, OUTPUT);
  pinMode(speaker2, OUTPUT);

  //setup for debouncing
  for(int i = 0; i < numSwitches; i++){
    bounce[i].attach(switchPins[i], INPUT_PULLUP);
    bounce[i].interval(5);
  }

  
}

void loop() {

  for(int i = 0; i < numSwitches; i++){
    //switchStates[i] = digitalRead(switchPins[i]);

    //read switch state
    bounce[i].update();
    int val = bounce[i].read();

    //play notes
      if( val == LOW ){
        int note_freq = cMinorHarmonic[i];
        tone(speaker1, note_freq);

        //optional LED
        analogWrite(ledPinRed, (int)(note_freq*sinh(note_freq)) % 255);
        analogWrite(ledPinGreen, note_freq % 255);
        analogWrite(ledPinBlue, (int)(note_freq*sin(note_freq)) % 255);
      }
    
      Serial.print("\tSwitch ");
      Serial.print(i);
      Serial.print(" is: ");
      Serial.print(val);
    
    
  }

  Serial.println();

//  int tone1 = 0;
//  for(int i = 0; i < numSwitches; i++){
//    if(switchStates[i] == LOW){
//      //if(tone1){
//        tone(speaker1, cMinorHarmonic[i]);
//        tone1 = 0;
//      //}
////      else{
////        tone(speaker2, cMajor[i]);
////        tone1 = 1;
////      }
//    }
//
//  }
//
  delay(10);
}
