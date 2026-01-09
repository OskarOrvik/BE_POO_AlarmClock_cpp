# BE_POO_AlarmClock
In this project we will do an alarm clock.

# Features
Screen
Buzzer
Light sensor
Button
LED

# Classes used
Year, Month, Day, Hour, Minutes, Seconds
Room -> Proprieties


# Libraries used
LiquidCrystal by adafruit
Adafruit BUSIO
Adafruit Liquicrystal 2.0.4
Adafruit MCP23017
Grove - LCD RGB Backlight
LiquidCrystal I2C



# To open port
sudo chmod a+rw /dev/ttyUSB0


# What we want:

En klokke som tar inn dag, time og minutt for å sette alarm.
Den skal spille av "Life is incredible" når vekkeklokken går. 
Samt en LCD som viser dato når vekkeklokken går
En knapp fra Arduino-kortet blir brukt for å skru av alarmen

# Configuartions of the Grove
The buzzer is configurated on pin: **D8**
The screen is configurated on pins: **I2C D1**

The button is configurated on pins: 
The lights-sensor is configurated on pins: 
The LED is configurated on pins: 

# Remarks
We tried to implement an RTC to show what time it is during wake up, but we do not have the RTC-module(Hardware)

