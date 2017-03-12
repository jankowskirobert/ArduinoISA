#include<ISALedControl.h>
#include<ISADefinitions.h>
ISALedControl led;

long x=7,y,w,z;

void setup() {
  y=random(8);
  led.init();
  led.clearDisplay();
  led.setLed(x, y,true);
  
  // put your setup code here, to run once:

}

void loop() {
  w=analogRead(JOY2X);
  if(w>900 && y<7)  
  {
    y++;
    led.clearDisplay();
    led.setLed(x, y,true);
  }
  else if(w<100 && y>0)
  {
    y--;
    led.clearDisplay();
    led.setLed(x, y,true);
  }
  
 /* z=analogRead(JOY2Y);
  if(z<100 && x<7)  
  {
    x++;
    led.clearDisplay();
    led.setLed(x, y,true);
  }
  else if(z>700 && x>0)
  {
    x--;
    led.clearDisplay();
    led.setLed(x, y,true);
  }
    else if(100<=w<=900 && x>=0 && x<7)
  {
    x++;
    led.clearDisplay();
    led.setLed(x, y,true);
  }
  */
  delay(100);
}
