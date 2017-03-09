#include <DueTimer.h>
#include "Buttons.h" 

Buttons button ;
int led_min = 2;
int led_max = 9;
int current_led = led_min;
bool state = false;
int actualTime=0;
void setup() {
  pinMode(2, OUTPUT); //led8
  pinMode(3, OUTPUT); //led7
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
Timer5.start(1000000);
Timer5.attachInterrupt(clockUp);
 button.init();
}
void clockUp(){
  actualTime++;
}


void loop() {

if (button.buttonPressed(0)) {
    Timer5.stop();
 }
 
if (button.buttonPressed(1)) {
Timer5.start(1000000);
 }
   if (button.buttonPressed(2)) {
    actualTime=0;
 }
  binary2LED(actualTime);
 delay(25);

}

void binary2LED(unsigned int value) {
  int i = 0;
  int l=2;
  for(;i<8;i++, l++){
    digitalWrite(l, value%2 );
    value/=2;
  }
}
