#include <ISALedControl.h>
ISALedControl led;
int analogFirstX = -1;
int analogFirstY = -1;
int analogSecondX = -1;
int analogSecondY = -1;
int posX = 4;
int posY = 4;
int mappedDestinationX = 0;
void setup()
{
  Serial.begin(9600);
  led.init();
//  led.setLed(posX, posY, true);
}
void loop() {

  analogSecondY = analogRead(A11);
  analogSecondX = analogRead(A10);

  if(analogSecondX > 550){
    mappedDestinationX = 1;
    if(analogSecondX > 850)
    mappedDestinationX = 3;
    }
  else if(analogSecondX < 480){
    mappedDestinationX = -1;
    if(analogSecondX < 200)
    mappedDestinationX = -3;
    }
  else 
    mappedDestinationX = 0;
  posX += mappedDestinationX;

  Serial.print(posX);
  Serial.print("/");
  Serial.print(posY);
  Serial.print(" ");
    Serial.print(analogSecondY);
  Serial.print("/");
  Serial.print(analogSecondX);
  Serial.println(" ");
  if(posX < 8 && posY < 8 && posY >= 0 && posX >= 0){
    led.clearDisplay();
    led.setLed(posX, posY, true);
  }
}
