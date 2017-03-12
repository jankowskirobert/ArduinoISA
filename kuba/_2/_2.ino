#include <ISADefinitions.h>
int j=4;
bool state = false;
void setup() {
 for(int i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);
    pinMode(KEY_RIGHT, INPUT);
    pinMode(KEY_LEFT, INPUT);
}


void loop() {
  delay(100);
  bool right = !digitalRead(KEY_RIGHT);
  bool left = !digitalRead(KEY_LEFT);
 digitalWrite(LEDS[j], HIGH);

if (right)
  {
  if(j != 7)
    {digitalWrite(LEDS[j], LOW);
  j++;}

  }
  if (left)
  {
  if(j != 0)
    {digitalWrite(LEDS[j], LOW);
  j--;}

  }
}
