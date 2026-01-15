#include "screen.hpp"

screen::screen(){};
screen::~screen(){};
void screen::initDisplay(rgb_lcd &screen){ //Function that initializes the LCD
  screen.begin(16, 2); // Set the size of the display
  screen.setRGB(0, 0, 255); // Change backlight colour
  screen.clear(); // Clear the screen
  
}
void screen::messageScreen(rgb_lcd &screen, const char * m){ //Function that sends a message to the LCD
  screen.clear();
  screen.print(m);

}

void screen::loopScreen(rgb_lcd &screen){
  screen.scrollDisplayLeft();
  delay(500);
  
}