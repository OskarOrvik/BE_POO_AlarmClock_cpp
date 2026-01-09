#ifndef _CLOCK_HPP
#define _CLOCK_HPP
//C/Arduiono-libraries
#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <iostream>
#include <Arduino.h>
//Headers used
#include "Application.h"

//Classes
class timeDay{
  private:
  protected:
    int d;
    int h;
    int m;
    int dm;
  public:
    timeDay();
    int begin(int day, int hour, int minute, int daymonth);
    int getHour(); 
    int getMinute(); 
    int getDayOfMonth(); 
    int getDayOfWeek();
    void setHour(int hour);
    void setMinute(int minute);
    void setDayWeek(int day);
    void setDayMonth(int daymonth);
};

class hour : timeDay{
  private:
  protected:
    hour(int h);
    int value;
    public:
};

class minute : timeDay{
  private:
  protected:
    minute(int m);
    int value;
  public:
};
class daymonth : timeDay{
  private:
  protected:
    daymonth(int dm);
    int value;
  public:
};
class dayweek : timeDay{
  private:
  protected:
    dayweek(int dw);
    int value;
  public:
};

class counter{
  private:
    volatile long remainingSec = 0;
    volatile bool countdownFinish = false;
  public:
  counter();
  ~counter();
    void initTimer();
    void testTimer();
    void counterOff();
    void setupTimer();
    int setCountdown(int hours, int minutes, int seconds);
    bool isFinished();
    volatile long* getRemainingSecPtr();
};

void TIM1_IThandler();



#endif