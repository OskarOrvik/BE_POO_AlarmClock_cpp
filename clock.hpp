#include "Application.h"
#include <iostream>
#ifndef _CLOCK_HPP
#define _CLOCK_HPP
using namespace std;

//or #pragma once
//Classes

class time{
  private:
  protected:
    enum class day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    day day;
    int hour;
    int minute
  public:
    time SetTime(day d, hour h, minute m) : day(d), hour(h), minute(m){
      
    }
};
 
class hour : tim

class time{
private:
protected:
  enum class day{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}
    public:
  };
  class hour{
    private:
    protected:
      explicit hour(int h = 0):value(h){
        if (h<0 || h>23){throw std::out("Hour needs be between 0 and 23 !");}
      }
      int value;
      public:
      };
  class minute{
    private:
    protected:
      explicit minute(int m = 0):value(m){
        if (m<0 || m>59){throw stdout<<"Minutes are to be between 0 and 59"<<endl;}
       }
       int value;
    public:
  };
};

#endif


  //setdate -> time.day = dagen, time.minute = minuttet,, time.hour = timen
  //int setDate(time.day dag, time.hour )

