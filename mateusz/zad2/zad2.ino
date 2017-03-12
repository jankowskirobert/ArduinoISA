#include <ISADefinitions.h>
int i = 0;
void setup() {
  for(i = 0;i<8;i++)
  {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  for(i = 0;i<8;i++)
  {
    if(i>0)
      digitalWrite(LEDS[i-1],LOW);
    digitalWrite(LEDS[i], HIGH);
    delay(200);
  }
  for(i = 7;i>=0;i--)
  {
    if(i < 7)
      digitalWrite(LEDS[i+1], LOW);
    digitalWrite(LEDS[i], HIGH);
    delay(200);
  }

}
