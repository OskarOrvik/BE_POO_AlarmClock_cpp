# BE_POO_AlarmClock

As a C++ project, we got the idea to do a Arduino project to use different parts of the C++ language benefits and workings.
For us this inludes:
- Classes
- Inheritance
- Standard library functions
  - cout

# What we want:

Originally:  
An alarm clock which includes date, day and time. The alarm could be set and plays the song "Life is increadible" to motivate you to start the day in a good way.  
The LCD screen shows a wake up message as well as the current date. The button could be used to turn off the alarm.

Final state:  
The alarm is based on countdown. The countdown is started using the button. This countown could be changed from some seconds to several hours and uses interruptions on the timer 1. After a set number of interruptions, time is up and the timer goes off, playing the wake up song using the buzzer component.

# Problems encountered

- We started out with an assumption that the ESP8266 had the capability to count the time, so we spent some time trying to make that part work. We found out later that this functionallity was not available for us, so that meant that we wasted a lot of time on the implementation of a feature we couldn't use in the end.

    - Lesson: Check the capabilities before starting the project

- Optimisation of the alarm clock ringing how we wanted was time consuming. This time could be better used to implement data structures and creation of new operators. Using an array to store the wanted countown duration could be stored in an array for exemple, where we could redefine the operator [].

    - Lesson: Creating a priority list and letting go of some features and fine-tuning of some features on a small project stops us from making a bigger and more diverse end product.

# Features
- LCD Screen
- Buzzer
- Button
- LED

# Classes used
- Peripherics class
  - Objects inheriting from peripheric class
- Application class

![UML Class Diagram](./UML_BE_AlarmClock "Class Diagram")



# Libraries used
LiquidCrystal by adafruit  
Adafruit BUSIO  
Adafruit Liquicrystal 2.0.4  
Adafruit MCP23017  
Grove - LCD RGB Backlight  
LiquidCrystal I2C  
RTClib  


# Configuartions of the equipment
The buzzer is configurated on pin: **D8**  
The screen is configurated on pins: **I2C**  
The button is configurated on pins: **D6**  
The LED is configurated on pins: **D3** (Mainly used for testing purposes)  
