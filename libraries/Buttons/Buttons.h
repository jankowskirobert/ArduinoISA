/*
  Display.h - Library for button handling.
  Created by Piotr Duch, December 30, 2016.
*/

#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

class Buttons
{
  public:
    Buttons();
    void init();
    bool buttonPressed( int );
    bool buttonReleased( int );
    bool buttonState( int );

  private:

    static const int numberOfButtons = 16;

    static const int latchPin = 40;
    static const int dataPin = 42;
    static const int clockPin = 41;

    static void refresh();
    static bool buttonsPressed[numberOfButtons];
    static bool buttonsReleased[numberOfButtons];
    static int buttonPins[numberOfButtons];
    static byte previousState1, previousState2;
    static volatile int buttonOldStates[numberOfButtons];
    static byte shiftIn(int myDataPin, int myClockPin); 

    static byte currentState1, currentState2;
    
};

#endif
