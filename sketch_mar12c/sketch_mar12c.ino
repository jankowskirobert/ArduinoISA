#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=0;
void setup() {
  // put your setup code here, to run once:
 lcd.begin();
lcd.print("hello, world!"); 


}

void loop() {
  // put your main code here, to run repeatedly:
  
lcd.clear();
int pot = analogRead(POT);
lcd.print(pot);
delay(250);
 if(pot<128){
 i=0;
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 
 if(pot>128 && pot<254){
 i=1;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
if(pot>256 && pot<384){
 i=2;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 if(pot>384 && pot<512){
 i=3;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 if(pot>512 && pot<640){
 i=4;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 if(pot>640 && pot<768){
 i=5;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 if(pot>768 && pot<896){
 i=6;
 digitalWrite(LEDS[i-1], LOW);
 digitalWrite(LEDS[i+1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }
 if(pot>896 && pot<1024){
 i=7;
 digitalWrite(LEDS[i-1], LOW);
 pinMode(LEDS[i],OUTPUT);
 digitalWrite(LEDS[i], HIGH);
 }

} 
