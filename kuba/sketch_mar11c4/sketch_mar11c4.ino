#include <ISADefinitions.h>
void setup() {
 pinMode(POT,INPUT);
 for(int i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);
}

void loop() {
  int pot = map(analogRead(POT),0,1023,0,7);
  
  digitalWrite(LEDS[pot],HIGH);
 
  delay(50);
    digitalWrite(LEDS[pot],LOW);
}

