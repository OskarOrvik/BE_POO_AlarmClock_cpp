#include "clock.hpp"
#include <Arduino.h>


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
dayweek::dayweek(int dw){if (dw < 1 || dw > 7) {
    std::cout << "Day needs be between 1 and 7 !" << std::endl;
  }
};

#define testPin D5
counter::counter(){};
counter::~counter(){};

void counter::initTimer(){
  pinMode(testPin, OUTPUT);
}
void counter::counterOff(){
  timer1_detachInterrupt();
  timer1_disable();
}
volatile long* gRemainingSec = nullptr;  // global pointer to remainingSec in counter
volatile bool* gCountdownFinish = nullptr; // global pointer to countdownFinish in counter
 IRAM_ATTR void TIM1_IThandler() {
  if (*gRemainingSec > 0) {
    (*gRemainingSec)--;
  }
  if(*gRemainingSec == 0){*gCountdownFinish = true;}
 }

int counter::setCountdown(int hours, int minutes, int seconds){
  if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
    return -1;
  }
  remainingSec = hours * 3600L + minutes*60L + seconds;
  countdownFinish = false;

  gRemainingSec = &remainingSec;       // point ISR to this counter's variable
  gCountdownFinish = &countdownFinish;

  timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
  timer1_write(312500); // 1s
  timer1_attachInterrupt(TIM1_IThandler);
  return 0;
}

bool counter::isFinished() {
    return countdownFinish;
}

volatile long* counter::getRemainingSecPtr() {
    return &remainingSec;  // give ISR access
}


