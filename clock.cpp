#include "clock.hpp"
#include <Arduino.h>
#include <RTClib.h>

#define testPin D5
int STOP = 10;
int interruptionCounter = 0;

void initTimer(){
  pinMode(testPin, OUTPUT);
}

void TIM1_IThandler(){
  digitalWrite(testPin, !digitalRead(testPin));
  interruptionCounter += 1;
  if(interruptionCounter > STOP){
    stop_alarm();
  }
}

void stop_alarm(){
  timer1_detachInterrupt();
  timer1_disable();
  ringAlarm = 1;
}

int setCountdown(int hours, int minutes, int seconds){
  if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
    return -1;
  }
  STOP = (60*(60*hours + minutes))+ seconds; // Unused for the moment. Will be used to stop the process
  timer1_write(312500); // 1s
  timer1_enable(TIM_DIV256, TIM_LEVEL, TIM_LOOP);
  timer1_attachInterrupt(TIM1_IThandler);
  return 0;
}

void setupTimer(){
  initTimer();
  setCountdown(0, 0, 20); // Example: set alarm for 20 sec
}

