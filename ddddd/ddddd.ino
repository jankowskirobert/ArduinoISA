#include <ISADefinitions.h>


void setup() {
  // put your setup code here, to run once:
   pinMode(LED1, OUTPUT);

}
int i=0;
void loop() {
 pinMode(LEDS[i], OUTPUT);
 digitalWrite(LEDS[i], HIGH);
if(analogRead(POT)%128==0){
  digitalWrite(LEDS[i], LOW);

 i=analogRead(POT)/128;
}
    
}
