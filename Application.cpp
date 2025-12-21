/*********************************************************************
 * @file  Apllication.cpp
 * @author Oskar Orvik & Brage Johnsen  
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
// Objects
screen myScreen; // Creation of own oject screen
rgb_lcd lcd_screen;  // Creation of object screen
button tactile; // Creation of button object

Application::Application() {
  // Code
  ;
}

Application::~Application() {
  // Code
  ;
}

void Application::init(void) {
  // Code
  myScreen.initDisplay(lcd_screen);
  tactile.setup();
}

void Application::run(void) {
  // Code
  tactile.verifyButton();
}
