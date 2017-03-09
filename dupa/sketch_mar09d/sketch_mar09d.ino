#include "Buttons.h" 
int value = 1 ;
Buttons button ;
void setup() {
    pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 button.init();
}

void loop() {
  if (button.buttonPressed(0)) {
    value = value+1;
 }
 
if (button.buttonPressed(1)) {
value = value-1;
 }
   if (button.buttonPressed(2)) {
    value = value<<1;
 }
 
if (button.buttonPressed(3)) {
value = value>>1;
 }
  binary2LED(value);
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
