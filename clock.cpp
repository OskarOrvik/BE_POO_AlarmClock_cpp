#include "clock.hpp"

time::time(){};
int time::GetDay() {
  return d;
}
int time::GetHour() {
  return h;
}
int time::GetMinute() {
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



int set_alarm(int heures, int minutes) {  // For an alarm going off after x hours and y minutes
  timer1_enabled();


  return 0;
}
