#include <DueTimer.h>
int led_min = 2;
int led_max = 9;
int current_led = led_min;
bool state = false;
void setup() {
  pinMode(2, OUTPUT); //led8
  pinMode(3, OUTPUT); //led7
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
Timer5.start(250000);
Timer5.attachInterrupt(outputFunc);

}
void outputFunc(){
  digitalWrite(led_max, 0);
  digitalWrite(current_led, 1);
  if(current_led > led_min)
    digitalWrite(current_led-1, 0);
  current_led++;
  if(current_led>led_max){
    current_led = led_min;
  }
}


void loop() {



}
