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
timeDay currentTime;
buzzer myBuzzer;

int activeAlarm = 0;
int ringAlarm = 0;

Application::Application()
  : hasRun(false) {  // initialize
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
  //setupTimer();
  pinMode(D6, INPUT); 
}


void Application::run(void) {
  if (!hasRun) {

    char mes[100] = "Luke, I'm your father!";
    myScreen.messageScreen(lcd_screen, mes);


    myBuzzer.BuzzerON();
    myBuzzer.buzzerPlay();
    myBuzzer.BuzzerOFF();
    hasRun = true;
    
  } else {
    myScreen.loopScreen(lcd_screen);
    //tactile.verifyButton();
    
    
    if (!activeAlarm && digitalRead(D6)){
       setupTimer();
       activeAlarm = 1;
    }

    if(ringAlarm){
      while(!digitalRead(D6)){
        myBuzzer.BuzzerON();
        myBuzzer.buzzerPlay();
        myBuzzer.BuzzerOFF();
      }
      ringAlarm = 0;
      activeAlarm = 0;
    }
  }
}
