#include "Buttons.h" 

Buttons button ;
int led_max = 9;
int led_min = 2;
int current_led = 6;
bool state = false;
void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 button.init();
digitalWrite(current_led, 1); 
}
void loop(){
  
 if (button.buttonPressed(0)) {
//state = !state;

current_led++;
checkState();
digitalWrite(current_led, 1);
digitalWrite(current_led-1, 0);
 }
 
if (button.buttonPressed(1)) {
current_led--;
checkState();
digitalWrite(current_led, 1);
digitalWrite(current_led+1, 0);

 }
delay(25);
}
void checkState(){
  if(current_led < led_min)
   current_led = led_min;
if(current_led > led_max)
current_led = led_max;
}

