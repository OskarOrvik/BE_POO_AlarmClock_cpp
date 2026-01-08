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

Application::Application() : hasRun(false) {  // initialize
    std::cout << "Application created" << std::endl;
}

Application::~Application() {
  // Code
  std::cout << "Application destroyed" << std::endl;
}



void Application::init(void) {
  // Code
  /*
  
  tactile.setup();
  currentTime.begin(00, 00, 00, 00);
  */
  myScreen.initDisplay(lcd_screen);
  myBuzzer.initBuzzer();
}

void Application::run(void) {
  if (hasRun) return;
  // Code
  //Get date
  //Maybe this could be done in another file?
  /*
  std::array<int,4> date = dateNow();
  timeDay currentTime;
  currentTime.setMinute(date[0]);
  currentTime.setHour(date[1]);
  currentTime.setDayWeek(date[2]);
  currentTime.setDayMonth(date[3]); 
  int m = currentTime.getMinute();
  int h = currentTime.getHour();
  int dw = currentTime.getDayOfWeek(); 
  int dm = currentTime.getDayOfMonth(); 
  day day_str;
  switch (dw) {case 1: day_str = Monday;break; case 2: day_str = Tuesday;break; case 3: day_str = Wednesday; break; case 4: day_str = Thursday;  break; case 5: day_str = Friday;break; case 6: day_str = Saturday;break; case 0: day_str = Sunday;break; default: break;}
  
  */
  char mes[100] = "Hello, I'm your father!";
  //snprintf(mes, sizeof(mes),"Wake up!, It's %02d.%02d the %d. And the day is %s",h,m,dm,myScreen.dayToString(day_str));
  myScreen.messageScreen(lcd_screen, mes); 

  

  myBuzzer.BuzzerON();
  myBuzzer.buzzerPlay();
  myBuzzer.BuzzerOFF();
  
  //tactile.verifyButton();
  hasRun=true;
  }
