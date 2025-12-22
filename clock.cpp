#include "clock.hpp"

time::time(){};
int time::getDay() {
  return d;
}
int time::getHour() {
  return h;
}
int time::getMinute() {
  return m;
}
int time::begin(int day, int hour, int minute){
  d = day;
  h = hour;
  m = minute;
  if (h<0 || h>23 || m<0 || m>59){
    return -1;
  }
  else{
    return 0;
  }
}

void time::setDay(int day){d = day;}
void time::setHour(int hour){h = hour;}
void time::setMinute(int minute){m = minute;}

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

const int testPin = D8;    // Onboard LED pin
void testTimer(){
  if ( digitalRead(testPin)){ // Toggle pin
    digitalWrite(testPin, LOW);
  }
  else{
    digitalWrite(testPin, HIGH);
  }
}

void TIM1_IThandler(){ // interrupt userFunc
  timer1_write(8388607-6250000); // 20s
  testTimer();
}

int set_alarm(int hours, int minutes) {  // For an alarm going off after x hours and y minutes
    if (hours<0 || hours>23 || minutes<0 || minutes>59){
    return -1;
  }
  else{
  int STOP = 60*(60*hours + minutes); // Unused for the moment. Will be used to stop the process
  timer1_enabled();
  timer1_enable(TIM_DIV256, TIM_EDGE, TIM_LOOP);
  timer1_attachInterrupt(TIM1_IThandler);
  return 0;
  }
}




