#include <ISADefinitions.h>

void setup() {
int licznik;

for(licznik = 0; licznik<8; licznik++)
   {
pinMode(LEDS[licznik], OUTPUT);
    }


}

void loop() {
int dioda;
int licznik;

for(licznik = 0; licznik<8; licznik++)
   {
    digitalWrite(LEDS[licznik], HIGH);
    delay(100);
    digitalWrite(LEDS[licznik], LOW);
  
   }

}
