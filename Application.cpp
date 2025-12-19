/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"

rgb_lcd screen;  // Creation of object screen
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
  initDisplay(screen);
  //tactile.setup();

}


void Application::run(void) {
  // Code
  //tactile.verifyButton();
}
