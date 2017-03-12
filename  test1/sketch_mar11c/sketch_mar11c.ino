#include<ISADefinitions.h>
int i;
void setup() {
  
}

void loop() {
  for(i=0; i<8; i++)
  {
   pinMode(LEDS[i], OUTPUT);
   digitalWrite(LEDS[i], HIGH);
   delay(100);
   digitalWrite(LEDS[i], LOW);
  }  
  for(i=6; i>0; i--)
  {
   digitalWrite(LEDS[i], HIGH);
   delay(100);
   digitalWrite(LEDS[i], LOW);
  }
}
