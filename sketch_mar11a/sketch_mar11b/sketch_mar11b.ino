#include <ISADefinitions.h>

void setup() {
  for(int i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);
}

void loop() 
{
  for(int i = 0; i < 8; i++)
   {
      digitalWrite(LEDS[i], HIGH);
      delay(100);
      digitalWrite(LEDS[i], LOW);
      delay(10);
   }
   for(int i = 6; i > 0; i--)
   {
      digitalWrite(LEDS[i], HIGH);
      delay(100);
      digitalWrite(LEDS[i], LOW);
      delay(10);
   }
   
}
