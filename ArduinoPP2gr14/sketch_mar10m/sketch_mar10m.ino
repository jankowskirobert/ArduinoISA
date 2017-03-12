#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons button;
  int licznik = 0;
  bool state = false;
void setup() {
  int licznik;

button.init();

  for(licznik = 0; licznik<8; licznik++)
   {
pinMode(LEDS[licznik], OUTPUT);
    }
pinMode(KEY_RIGHT, INPUT);
}
void loop() {

   digitalWrite(LEDS[licznik], HIGH);
  if (!digitalRead(KEY_RIGHT)){
      state = !state;
      digitalWrite(LEDS[licznik+1], HIGH);
      licznik=licznik+1;
      
  }digitalWrite(LEDS[licznik], LOW);
  delay(100);

if (!digitalRead(KEY_LEFT)){
      state = !state;
     

      licznik=licznik-1;
      
  }digitalWrite(LEDS[licznik], LOW);
   
   delay(100);
}
