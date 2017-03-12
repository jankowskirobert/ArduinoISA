#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int pot;
int licznik;
void setup() {
   licznik = 0;
  pot = analogRead(POT);
  
  int temp;
  
for(licznik = 0; licznik<8; licznik++)
   {
pinMode(LEDS[licznik], OUTPUT);
    }
}


void loop() {
 
 
 digitalWrite(LED1, HIGH);
 if(pot>analogRead(POT)){
   digitalWrite(LEDS[licznik-1], HIGH);
   licznik=licznik-1;
 }
    delay(250);
 
 if(pot<analogRead(POT)){
   digitalWrite(LEDS[licznik+1], HIGH);
   licznik=licznik+1;
 }




}
