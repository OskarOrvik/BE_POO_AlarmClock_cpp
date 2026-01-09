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
buzzer myBuzzer;
counter myCounter;


Application::Application() : hasRun(false) {  // initialize
    std::cout << "Application created" << std::endl;
}

Application::~Application() {
  // Code
  std::cout << "Application destroyed" << std::endl;
  timer1_disable();         // Disable the timer
}

void Application::init(void) {
  Wire.begin(D2, D1);
  delay(50);
  currentTime.begin(00, 00, 00, 00);
  tactile.setup();
  myBuzzer.initBuzzer();
  myCounter.initTimer();
  Wire.begin(D2, D1);  // SDA, SCL pins on ESP8266 NodeMCU
  myScreen.initDisplay(lcd_screen);
}

void Application::run(void) {  
  static bool countdownStarted = false;
    if (!countdownStarted) {
        myCounter.setCountdown(0, 0, 10); // 20s countdown
        countdownStarted = true;
    }

    // Continuously check if countdown finished
    if (myCounter.isFinished()) {
        myScreen.messageScreen(lcd_screen, "Wake up! It's time to shine!");
        for (int i = 0; i < 3; i++) {
            myBuzzer.BuzzerON();
            myBuzzer.buzzerPlay();
            delay(4000);
        }
        myBuzzer.BuzzerOFF();
        hasRun = true;
        myCounter.counterOff(); // stop the timer
    } else {
        myScreen.loopScreen(lcd_screen);
    }
}