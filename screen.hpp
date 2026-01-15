#ifndef SCREEN_H_
#define SCREEN_H_
#include "peripheral.hpp"
#include <rgb_lcd.h>

class screen : public peripheral{
  public:
  screen();
  ~screen();
  void initDisplay(rgb_lcd &screen); 
  void messageScreen(rgb_lcd &screen, const char * m);
  void loopScreen(rgb_lcd &screen);
};

#endif // SCREEN_H_
