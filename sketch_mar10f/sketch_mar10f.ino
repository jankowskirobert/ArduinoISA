#include <ISALedControl.h>
ISALedControl led;
int off = 0;
int dir = 1;
void setup()
{
led.init();

}
void loop() {
spin(off++, true);
if(off > 3){
  off = 0;
  led.clearDisplay();
}
}
void spin(int offset, bool flag) {
    int leds = 0;
    for(leds = offset; leds < 8-offset; leds++) {
      led.setLed(leds, offset, flag);
      delay(100);
    }
    for(leds = offset; leds < 8-offset; leds++) {
      led.setLed(7-offset, leds, flag);
      delay(100);
    }
    for(leds = offset; leds < 8-offset; leds++) {
      led.setLed(7-leds, 7-offset, flag);
      delay(100);
    }
    for(leds = offset; leds < 8-offset; leds++) {
      led.setLed(offset, 7-leds, flag);
      delay(100);
    }
    
  
}

