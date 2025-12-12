#include "rgb_lcd.h"
#include "Application.h"

#include <Wire.h>

Application alarmClock;

void setup() {
  // put your setup code here, to run once:
  alarmClock.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  alarmClock.run();
}
