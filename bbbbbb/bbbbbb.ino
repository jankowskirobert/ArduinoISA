#include <ISADefinitions.h>

void setup() {
  // put your setup code here, to run once:

}
int i=0;
int tyl=0;
void loop() {
 pinMode(LEDS[i], OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 delay(analogRead(POT));
 digitalWrite(LEDS[i], LOW);
 if(tyl==0)
  i++;
 else
  i--;

  if(i==0)
    tyl=0;
  else if(i==7)
    tyl=1;
 
 
    
}
