#include "Application.h"
#include <iostream>
#ifndef _CLOCK_HPP
#define _CLOCK_HPP

//or #pragma once
//Classes

class time{
  private:
  protected:
    enum class day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    day d;
    int h;
    int m;
    public:
    time Time(day d, int h, int m) : day(d), hour(h), minute(m){
      if(h<0 || h>23){std::cout<<"Hour needs be between 00:00 and 23:00"<<endl;}
      if(m<0 || m>59){std::cout<<"Minutes needs be between 0 and 59"<<endl;}
    }
    int GetHour(){return hour;}
    int GetMinute(){return minute}
    day GetDay(){return day;}
};
 
#endif


  //setdate -> time.day = dagen, time.minute = minuttet,, time.hour = timen
  //int setDate(time.day dag, time.hour )

