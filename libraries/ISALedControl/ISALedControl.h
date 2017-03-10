/*
  Display.h - Library for button handling.
  Created by Piotr Duch, December 30, 2016.
*/

#ifndef ISALedControl_h
#define ISALedControl_h

#include "Arduino.h"

class ISALedControl
{
  public:
    ISALedControl();
	void init();
    void clearDisplay( );
    void setRow( byte, byte );
    void setColumn( byte, byte );	
    void setLed( byte, byte, byte );
	
  private:

    void maxTransfer(uint8_t, uint8_t);
	const int LOAD_PIN = 43;
    
    byte columnState[8];
    
};

#endif
