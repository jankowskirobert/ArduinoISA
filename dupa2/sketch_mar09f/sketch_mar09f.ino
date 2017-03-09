
#include "Buttons.h" 
Buttons button ;
int led_min = 2;
int led_max = 9;
int value = 0;
int displayed = 0;
void setup() {
  pinMode(2, OUTPUT); //led8
  pinMode(3, OUTPUT); //led7
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
    //7 
    value = value*10 + 7;
 }
 
if (button.buttonPressed(1)) {
value = value*10 + 8;
 }
   if (button.buttonPressed(2)) {
value = value*10 + 9;
 }
   if (button.buttonPressed(4)) {
value = value*10 + 4;
 }
    if (button.buttonPressed(5)) {
value = value*10 + 5;
 }
    if (button.buttonPressed(6)) {
value = value*10 + 6;
 }
    if (button.buttonPressed(8)) {
value = value*10 + 1;
 }
    if (button.buttonPressed(9)) {
value = value*10 + 2;
 }
    if (button.buttonPressed(10)) {
value = value*10 + 3;
 }
     if (button.buttonPressed(12)) {
value = 0;
  displayed = value;
 }
     if (button.buttonPressed(13)) {
value = value*10;
 }
 
     if (button.buttonPressed(14)) {
  displayed = value;
  value = 0;
 }
 binary2LED(displayed);
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
