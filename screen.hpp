#ifndef SCREEN_H_
#define SCREEN_H_
#include "peripheral.hpp"
#include <rgb_lcd.h>
class screen : peripheral{
  public:
  screen();
  ~screen();
  void initDisplay(rgb_lcd screen);
};

#endif // SCREEN_H_
