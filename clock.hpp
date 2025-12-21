#ifndef _CLOCK_HPP
#define _CLOCK_HPP
//Libraries
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include "Application.h"
#include <iostream>
#include <Arduino.h>



//Classes

class time{
  private:
  protected:
    int d;
    int h;
    int m;
  public:
    time();
    int begin(int day, int hour, int minute);
    int GetHour();
    int GetMinute();
    int GetDay();
};

enum day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

class hour : time{
  private:
  protected:
    hour(int h);
    int value;
    public:
};

class minute : time{
  private:
  protected:
    minute(int m);
    int value;
  public:
};



/* 
class hour : time

class time{
private:
protected:
  enum class day{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}
    public:
  };
{
    

{
      if (m<0 || m>59){std::cout << "Minutes are to be between 0 and 59" << std::endl;}

};

    time Time(day d, int h, int m) : day(d), hour(h), minute(m){
      if(h<0 || h>23){std::cout<<"Hour needs be between 00:00 and 23:00"<<endl;}
      if(m<0 || m>59){std::cout<<"Minutes needs be between 0 and 59"<<endl;}
    }

public:
};
/*
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

*/
#endif


  //setdate -> time.day = dagen, time.minute = minuttet,, time.hour = timen
  //int setDate(time.day dag, time.hour )

