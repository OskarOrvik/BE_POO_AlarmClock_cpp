/*********************************************************************
 * @file  Apllication.cpp
 * @author Oskar Orvik & Brage Johnsen  
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Arduino.h>
// Objects
screen myScreen;     // Creation of own oject screen
rgb_lcd lcd_screen;  // Creation of object screen
button tactile;      // Creation of button object
buzzer myBuzzer;     // Creation of buzzer object

int activeAlarm = 0;
int ringAlarm = 0;

Application::Application() : hasRun(false) {  // initialize
  std::cout << "Application created" << std::endl;
}

Application::~Application() {
  // Code
  std::cout << "Application destroyed" << std::endl;
  //timer1_disable();         // Disable the timer
}



void Application::init(void) {
  // Code
  tactile.setup();
  myScreen.initDisplay(lcd_screen);
  myBuzzer.initBuzzer();
  initTimer();
}


void Application::run(void) {
  if (!hasRun) {

    char mes1[100] = "Johnsen & Orvik Co";
    myScreen.messageScreen(lcd_screen, mes1);
    delay(5000);
    char mes2[100] = "Countdown machine";
    myScreen.messageScreen(lcd_screen, mes2);
    delay(4000);
    
    

    //myBuzzer.BuzzerON();
    //myBuzzer.buzzerPlay();
    //myBuzzer.BuzzerOFF();
    hasRun = true;
    
  } else {
    myScreen.loopScreen(lcd_screen);
    
    if (!activeAlarm && tactile.readButton()){
       setupTimer();
       activeAlarm = 1;
    }

    if(ringAlarm){
      char mes3[100] = "Wake up !!! Wake up !!!";
      myScreen.messageScreen(lcd_screen, mes3);
      myBuzzer.BuzzerON();
      myBuzzer.buzzerPlay();
      myBuzzer.BuzzerOFF();  
      ringAlarm = 0;
      activeAlarm = 0;
      
    
    }
  }
}
