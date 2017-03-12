#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>

ISALiquidCrystal lcd;


void illumination(int t) {
  for(int n = 8; n > 3; n--) {
     
    for (int i = 8-n; i < n; i++) {
      digitalWrite(LEDS[i], HIGH);
      delay(t);
      digitalWrite(LEDS[i], LOW);
    }

    for (int i = (n-1); i > (9 - n); i--) {
      digitalWrite(LEDS[i], HIGH);
      delay(t);
      digitalWrite(LEDS[i], LOW);
    }
  }  

  for(int n = 4; n < 8; n++) {

    for (int i = (8-n); i > (9 - n); i--) {
      digitalWrite(LEDS[i], HIGH);
      delay(t);
      digitalWrite(LEDS[i], LOW);
    }
    
    for (int i = (9-n); i > (); i-) {
      digitalWrite(LEDS[i], HIGH);
      delay(t);
      digitalWrite(LEDS[i], LOW);
    }

  }  
}



void setup() 
{

  for (int i = 0;  i < 8; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  
}

void loop() {

  illumination (200);

  }
