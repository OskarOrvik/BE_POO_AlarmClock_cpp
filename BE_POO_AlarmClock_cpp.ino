#include "rgb_lcd.h"
#include "Application.h"

#include <Wire.h>
rgb_lcd screen; // Creation of local variable screen
void setup() {
  // put your setup code here, to run once:

  screen.begin(16, 2); // Set the size of the display
  screen.setRGB(255, 0, 0); // Change backlight colour
  screen.rgb_lcd::clear();
  screen.print("Wake up !!!");
  //Application::Application();
  //Application::init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Application::run();
}
