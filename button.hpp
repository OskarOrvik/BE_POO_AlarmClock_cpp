#pragma once
#include "peripheral.hpp"
#include <Arduino.h>

class button : public peripheral{
  public:
    void setup();
    int verifyButton();
    button();
    ~button();
};