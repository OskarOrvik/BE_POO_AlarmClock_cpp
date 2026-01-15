/*********************************************************************
 * @file  Apllication.h
 * @author Brage Johnsen and Oskar Orvik
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_
// C/Arduino-libraries
#include <rgb_lcd.h>
#include <Wire.h>
#include <iostream>
//Headers
#include "button.hpp"
#include "screen.hpp"
#include "clock.hpp"
#include "buzzer.hpp"

extern int activeAlarm;
extern int ringAlarm;

/**
  * @class Application
  * @brief Classe Application 
*/
class Application {
private:
  bool hasRun;
public:
  /**
     * @fn Application();
     * @brief Constructeur par defaut
    */
  Application();
  /**
     * @fn Application();
     * @brief Destructeur
    */
  ~Application();
  /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
  void init(void);
  /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
  void run(void);
};
#endif