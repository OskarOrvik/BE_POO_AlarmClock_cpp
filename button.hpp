#pragma once
#include "peripheral.hpp"
class button : public peripheral{
  public:
    void setup();
    int verifyButton();
    button();
    ~button();
};