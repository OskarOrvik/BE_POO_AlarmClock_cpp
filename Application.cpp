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
timeDay currentTime;
//buzzer myBuzzer;

Application::Application() : hasRun(false) {  // initialize
    std::cout << "Application created" << std::endl;
}

Application::~Application() {
  // Code
  std::cout << "Application destroyed" << std::endl;
  timer1_disable();         // Disable the timer
}



void Application::init(void) {
  // Code
  /*
  
  
  currentTime.begin(00, 00, 00, 00);
  */
  tactile.setup();
  myScreen.initDisplay(lcd_screen);
  //myBuzzer.initBuzzer();
  initTimer();
}

void Application::run(void) {
  if (! hasRun){

  char mes[100] = "Luke, I'm your father!";
  myScreen.messageScreen(lcd_screen, mes); 

  Serial.print("char");

  //myBuzzer.BuzzerON();
  //myBuzzer.buzzerPlay();
  //myBuzzer.BuzzerOFF();
  
  //tactile.verifyButton();
  hasRun=true;
  }
  else{
  myScreen.loopScreen(lcd_screen);
  //tactile.verifyButton();
  setupTimer();
  }
  }
