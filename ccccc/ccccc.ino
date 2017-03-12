#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons button;

void setup() {
  // put your setup code here, to run once:
   pinMode(LED1, OUTPUT);
 button.init();
}
int i=0;
void loop() {
 pinMode(LEDS[i], OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 

  if (button.buttonPressed(7)) {
    digitalWrite(LEDS[i], LOW);
    if(i==0){
       i=7;
     }
     else i--; 
    }
 
  if (button.buttonPressed(5)) {
    digitalWrite(LEDS[i], LOW);
    if(i==7){
      i=0;
    }
   else i++; 
  }delay(50); 
    
}
