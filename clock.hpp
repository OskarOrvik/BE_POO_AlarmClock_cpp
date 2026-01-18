#ifndef _CLOCK_HPP
#define _CLOCK_HPP
//C/Arduiono-libraries
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <iostream>
#include <Arduino.h>
//Headers used
#include "Application.h"
#include "buzzer.hpp"


void initTimer();
void testTimer();
void stop_alarm();
void setupTimer();
void TIM1_IThandler();
int setCountdown(int hours, int minutes,int seconds);


#endif