#include <ISALedControl.h>
ISALedControl led;
bool leds[8][8] ;
void setup()
{
  setUpLeds();
  led.init();
  randomSeed(analogRead(0));
}
void loop() {
  int kol=random(8);
  int i;
  for(i=0;i<8;i++){
    led.setLed(i, kol, true);
    delay(100);
    if(!leds[i][kol])
      led.setLed(i, kol, false);
    if(i == 7 || leds[i+1][kol]){ 
      leds[i][kol] = true;
      turnOnLeds();
    }
    
  }


}
void setUpLeds() {
int i = 0; 
int j = 0;
for(i = 0 ; i < 8 ; i++) {
  for(j = 0 ; j < 8 ; j++) {
    leds[i][j] = false;
  }
}
}
void turnOnLeds() {
int i = 0; 
int j = 0;
for(i = 0 ; i < 8 ; i++) {
  for(j = 0 ; j < 8 ; j++) {
    led.setLed(i, j, leds[i][j]);
  }
}
}

