#include <ISALedControl.h>
ISALedControl led;
int analogFirstX = -1;
int analogFirstY = -1;
int analogSecondX = -1;
int analogSecondY = -1;
int posX = 4;
int posY = 4;
int mappedFirstX = -1;
int mappedFirstY = -1;
void setup()
{
  Serial.begin(9600);
  led.init();
//  led.setLed(posX, posY, true);
}
void loop() {

  analogSecondY = analogRead(A10);
  analogSecondX = analogRead(A11);

  mappedFirstX = map(analogFirstX, 0, 550, -1,1);
  mappedFirstY = map(analogFirstY, 0, 550, -1,1);
  posX += mappedFirstX;
  posY += mappedFirstY;
  Serial.print(posX);
  Serial.print("/");
  Serial.print(posY);
  Serial.print(" ");
    Serial.print(mappedFirstX);
  Serial.print("/");
  Serial.print(mappedFirstY);
    Serial.print(" ");
    Serial.print(analogSecondY);
  Serial.print("/");
  Serial.print(analogSecondX);
  Serial.println(" ");
  if(posX < 8 && posY < 8 && posY >= 0 && posX >= 0){
    led.setLed(posX, posY, true);
  }else{
    posX = 4;
    posY = 4;}
    delay(150);
  }
