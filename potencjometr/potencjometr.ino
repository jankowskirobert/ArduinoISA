#include <ISADefinitions.h>
#include<ISALiquidCrystal.h>
ISALiquidCrystal lcd;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  int pot = analogRead(POT);
    lcd.print(pot);
    delay(250);
    pinMode(LEDS[pot/128],OUTPUT);
    digitalWrite(LEDS[pot/128],HIGH);
    for(int i=0;i<8;i++)
    if(i!=pot/128)digitalWrite(LEDS[i],LOW);
}
