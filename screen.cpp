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

  const char * screen::dayToString(day d) { //Function that converts the enumerated type day to printable strings
  switch (d) {
    case Monday:    return "Monday";
    case Tuesday:   return "Tuesday";
    case Wednesday: return "Wednesday";
    case Thursday:  return "Thursday";
    case Friday:    return "Friday";
    case Saturday:  return "Saturday";
    case Sunday:    return "Sunday";
    default:        return "?";
  }
}
void screen::loopScreen(rgb_lcd &screen){
  screen.scrollDisplayLeft();
  delay(500);
}