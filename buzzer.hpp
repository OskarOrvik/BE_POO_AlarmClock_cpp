#ifndef BUZZER_H_
#define BUZZER_H_
#include "peripheral.hpp"

class buzzer : public peripheral{
  public:
  buzzer();
  ~buzzer();
  void initBuzzer();
  void BuzzerON();
  void BuzzerOFF();
  void buzzerPlay();
  void buzzerMute();
  

};

void IT_Alarm();
void buzzerMute();

#endif