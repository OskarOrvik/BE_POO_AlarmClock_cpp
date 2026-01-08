#include "pitches.h"
#include "buzzer.hpp"
#include <Arduino.h>
 
 //Constants:
// notes in the "Life's incredible again":
//Bb5,C5,Bb5
const int melody[] = {
  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_F5,
  NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_FS5,
  NOTE_D5, NOTE_AS5, NOTE_G5, 0, NOTE_D5,
  NOTE_D5, NOTE_G5, NOTE_F5, 0,NOTE_C5,
  NOTE_D5, NOTE_G5, 0, NOTE_C6, 0, NOTE_AS5, NOTE_F5, 0, NOTE_C6, 0, NOTE_AS5,
  0, NOTE_AS5, NOTE_A5, 0, NOTE_G5,
  0, 0, 0, 0,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
const int noteDurations[] = {
  6, 2, 4, 8,
  6, 2, 4, 8,
  4, 2, 6, 4, 6,
  4, 2, 6, 4, 6,
  6, 1, 4, 1, 2, 4, 4, 4, 2, 4, 6,
  2, 2, 4, 2, 2,
  1, 1, 1, 1,
};
const int BuzzerPin = D8;

buzzer::buzzer(){};
buzzer::~buzzer(){};

//Functions
void buzzer::initBuzzer(){
  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, LOW);
}
void buzzer::BuzzerON(){
  digitalWrite(BuzzerPin, HIGH);
}
void buzzer::BuzzerOFF(){
  digitalWrite(BuzzerPin, LOW);
}
void buzzer::buzzerPlay() {
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]) ; thisNote++) {
    // to calculate the note duration, take one second divided by the note type. E.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BuzzerPin, melody[thisNote], noteDuration); //tone(pin, frequency, duration[ms])
    // to distinguish the notes, set a minimum time between them. The note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);
    noTone(BuzzerPin); // stop the tone playing:
  }
}