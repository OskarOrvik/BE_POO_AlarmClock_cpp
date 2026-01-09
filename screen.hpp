#ifndef SCREEN_H_
#define SCREEN_H_
#include "peripheral.hpp"
#include "day.hpp"
#include <rgb_lcd.h>

class screen : public peripheral{
  public:
  screen();
  ~screen();
  void initDisplay(rgb_lcd &screen); 
  void messageScreen(rgb_lcd &screen, const char * m);
  const char* dayToString(day d);
  void loopScreen(rgb_lcd &screen);
};

#endif // SCREEN_H_
