#include <ISADefinitions.h>
#include <ISAButtons.h>

ISAButtons button;
int j;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++)
  {
      pinMode(LEDS[i],OUTPUT);
  }
  digitalWrite(LEDS[0],HIGH);
  button.init();
  j=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button.buttonPressed(0))
  {
    if(j>0)
    {
    digitalWrite(LEDS[j],LOW);
    digitalWrite(LEDS[j-1],HIGH);
    j--;
    }
  }
    
  if(button.buttonPressed(1))
  {
    if(j<6)
    {
    digitalWrite(LEDS[j+1],HIGH);
    digitalWrite(LEDS[j],LOW);
    j++;
    }
  }

    
    
    
  
}
