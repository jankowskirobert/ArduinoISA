/*
  Display.h - Library for button handling.
  Created by Piotr Duch, December 30, 2016.
*/

#ifndef ISAButtons_h
#define ISAButtons_h

#include "Arduino.h"

class ISAButtons
{
  public:
    ISAButtons();
    void init();
    bool buttonPressed( int );
    bool buttonReleased( int );
    bool buttonState( int );

  private:

    #define numberOfButtons 16

    const int latchPin = 40;
    const int dataPin = 42;
    const int clockPin = 41;

    unsigned long timeOfLastButtonUpdate = 0;

    void refresh();
    
    bool buttonsPressed[numberOfButtons];// = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
    bool buttonsReleased[numberOfButtons];// = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

    int buttonPins[numberOfButtons];
    int buttonOldStates[numberOfButtons];
    byte shiftIn(int myDataPin, int myClockPin); 

    byte previousState1 = 255;
    byte previousState2 = 255;

    byte currentState1 = 255;
    byte currentState2 = 255;
    
};

#endif
