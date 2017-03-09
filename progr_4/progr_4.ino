#include <LedControl.h>

LedControl lc = LedControl(12,11,10,1);

unsigned long delaytime=90;

void setup()
{
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  lc.setLed(0,0,0,true);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8; i++)
  {
    lc.setLed(0,i,i,true);
  }
  
  int j=7;
  for(int i=0; i<8; i++)
  {
    lc.setLed(0,i,j,true);
    j--;
  }
  
  for(int i=0; i<8; i++)
  {
     int z=7;
     lc.setLed(0,i,z,true);
  }

  for(int i=0; i<8; i++)
  {
     int z=0;
     lc.setLed(0,i,z,true);
  }

  for(int i=0; i<8; i++)
  {
     int z=0;
     lc.setLed(0,z,i,true);
     z=7;
     lc.setLed(0,z,i,true);
  }

  
}
