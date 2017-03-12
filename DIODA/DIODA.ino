#include <ISADefinitions.h>
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<8;i++)
  {
    pinMode(LEDS[i],OUTPUT);
    digitalWrite(LEDS[i],HIGH);
    delay(500);
    digitalWrite(LEDS[i],LOW);
  }
  for(i=1;i<7;i++)
  {
    digitalWrite(LEDS[7-i],HIGH);
    delay(500);
    digitalWrite(LEDS[7-i],LOW);
  }
}
