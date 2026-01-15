#include "clock.hpp"
#include <Arduino.h>
#include <RTClib.h>


timeDay::timeDay(){};
int timeDay::getDayOfWeek() {
  return d;
}
int timeDay::getHour() {
  return h;
}
int timeDay::getMinute() {
  return m;
}
int timeDay::getDayOfMonth() {
  return dm;
}

int timeDay::begin(int day, int hour, int minute, int daymonth){
  d = day;
  h = hour;
  m = minute;
  dm = daymonth;
  if (h<0 || h>23 || m<0 || m>59){
    return -1;
  }
  else{
    return 0;
  }
}

void timeDay::setDayWeek(int day){d = day;}
void timeDay::setHour(int hour){h = hour;}
void timeDay::setMinute(int minute){m = minute;}
void timeDay::setDayMonth(int daymonth){dm = daymonth;}

minute::minute(int m) {
  if (m < 0 || m > 59) {
    std::cout << "Minutes are to be between 0 and 59" << std::endl;
  }
};
hour::hour(int h) {
  if (h < 0 || h > 23) {
    std::cout << "Hour needs be between 0 and 23 !" << std::endl;
  }
};
daymonth::daymonth(int dm){ 
  if (dm < 1 || dm > 31) {
    std::cout << "Date needs be between 1 and 31 !" << std::endl;
  }
};

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
  setCountdown(0, 0, 20); // Example: set alarm for 1 minute
}

