/*
  Led.h - Library for turn on and off leds.
  Created by Esteban J Pagano, https://github.com/elpagano
  Licence MIT.
*/

#ifndef Leds_h
#define Leds_h
 
#include "Arduino.h"

class Led{
// ----------- definir led
public:

  Led(int led1, int led2, int led3, int led4);// constructor
  
  void goLuces();
  void goLucesOff();
  void led_blink();
private:
  int _led1;
  int _led2;
};

#endif

/*

#ifndef Morse_h
#define Morse_h
 
#include "Arduino.h"
 
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};
 
#endif
*/
