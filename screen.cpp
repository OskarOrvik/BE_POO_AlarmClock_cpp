#include "screen.hpp"

void initDisplay(rgb_lcd screen){
  screen.begin(16, 2); // Set the size of the display
  screen.setRGB(0, 0, 255); // Change backlight colour
  screen.clear(); // Clear the screen
  screen.print("Wake up !!! Wake up !!!"); // Print wake-up message
  
}
