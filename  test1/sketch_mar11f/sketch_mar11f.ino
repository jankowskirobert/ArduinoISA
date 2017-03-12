#include<ISADefinitions.h>
#include<ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i;

void setup() {
  lcd.begin();
  for(i=0; i<8; i++)
  {
   pinMode(LEDS[i], OUTPUT); 
  }
}

void loop() {
  lcd.clear();
  int pot = analogRead(POT);
  if(pot>0&&pot<128)
    digitalWrite(LED1, HIGH);
  else
  lcd.print(pot);
  delay(250);
}
