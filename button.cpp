#include <Arduino.h>
#include "button.hpp"

// Define the pin connected to the Grove Button
const int buttonPin = D3;  // Signal pin of the Grove Button
const int ledPin = D5;    // Onboard LED pin

// Constructor/destructor
button::button(){};
button::~button(){};

void button::setup() {
  pinMode(buttonPin, INPUT);  // Set the button pin as input
  pinMode(ledPin, OUTPUT);   // Set the LED pin as output
}

int button::verifyButton(){
  if ( digitalRead(buttonPin)){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  return 0;
}
