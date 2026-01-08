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
//Use of REAL TIME CLOCK, defined underneath
RTC_DS3231 rtc; //Creating Real Time Clock
//Initialisation du RTC
void setupRTC() {
  Serial.begin(9600);
  
  if (!rtc.begin()) {  // Check if RTC is connected
    Serial.println("Real Time Clock not found!"); // It's printed in the arduino IDE
    while (1);         // Stop if not found
  }
}


std::array<int,4> dateNow(){
  DateTime now = rtc.now();
  std::array<int,4> listTime;
  listTime[0] = now.minute();
  listTime[1] = now.hour();
  listTime[2] = now.dayOfTheWeek();
  listTime[3] = now.day();
  return listTime;
}




