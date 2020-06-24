/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
 
#include "Arduino.h"
#include "Leds.h"
 
Led::Led(int _led1, int _led2,  int _led3,  int _led4 )
{
   //led
  pinMode(_led1, OUTPUT);              
  pinMode(_led2, OUTPUT);
}
 

void Led::goLuces(){ 
  digitalWrite(_led1, HIGH);
  digitalWrite(_led2, HIGH);
}

void Led::goLucesOff(){ 
  digitalWrite(_led1, LOW);
  digitalWrite(_led2, LOW);
}

void Led::led_blink(){
 int var = 0;
  while (var < 4) {
    digitalWrite(_led1, HIGH);
    digitalWrite(_led2, LOW);
    delay(90);                       // wait for a second
    
    digitalWrite(_led2, HIGH);
    digitalWrite(_led1, LOW);
    delay(90);                       // wait for half second
    
    digitalWrite(_led2, LOW);
    
    var ++;
  }

}
