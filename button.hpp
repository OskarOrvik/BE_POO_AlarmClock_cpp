#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "peripheral.hpp"
#include <Arduino.h>

class button : public peripheral{
  public:
    void setup();
    int verifyButton();
    int readButton();
    button();
    ~button();
    
};


#endif