#ifndef _CLOCK_HPP
#define _CLOCK_HPP
//Libraries
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include "Application.h"
#include <iostream>
#include <Arduino.h>

/*

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
 
class hour : time

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

public:
};
*/
class day{
private:
protected:
public:

};

class hour{
private:
protected:  
  int hours;
public:
};

class minute{
private:
protected:
  int minutes;
public: 
};


#endif


  //setdate -> time.day = dagen, time.minute = minuttet,, time.hour = timen
  //int setDate(time.day dag, time.hour )

