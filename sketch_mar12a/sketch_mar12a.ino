#include <ISADefinitions.h>

void setup() {
int i;
for(i=0;i<8;i++)
{
  pinMode(LEDS[i],OUTPUT);
}
}
void loop() {
 int i;
for(i=0;i<8;i++)
{
  digitalWrite(LEDS[i],HIGH);
  if(i>=1)
  {
  digitalWrite(LEDS[i-1],LOW);
  }
  delay(10);
  if(i==7) digitalWrite(LEDS[i],LOW);
  delay(10);
}
for(i=7;i>=0;i--)
{
  digitalWrite(LEDS[i],HIGH);
  if(i<=6)
  {
  digitalWrite(LEDS[i+1],LOW);
  }
  delay(10);
  if(i==0) digitalWrite(LEDS[i],LOW);
  delay(10);

}
}
