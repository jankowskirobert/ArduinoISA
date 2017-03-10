#include <ISALedControl.h>
ISALedControl led;
void setup()
{
led.init();
int i=0;
int j=0;
for(i=0;i<8;i++){
  for(j=0;j<8;j++){
    if((i+j)%2==1)
      led.setLed(i, j, true);
  }
}
}
void loop() {}
