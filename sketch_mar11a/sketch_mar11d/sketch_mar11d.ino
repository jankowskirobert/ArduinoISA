#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>

ISALiquidCrystal lcd;

void setup() {
  lcd.begin();
  lcd.clear();
  for(int i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);
  digitalWrite(LEDS[0], HIGH);
  pinMode(KEY_RIGHT, INPUT);
  pinMode(KEY_LEFT, INPUT);
}

int i = 0;

void loop() {

  if(!(digitalRead(KEY_RIGHT)))
  {   
      if(i < 7)
      {
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], LOW);
        delay(100);
        i++;
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], HIGH);
      }
      else
      {
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], LOW);
        delay(100);
        i = 0;
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], HIGH);
      }
  }
  
  if(!(digitalRead(KEY_LEFT)))
  {   
      if(i > 0)
      {
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], LOW);
        delay(100);
        i--;
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], HIGH);
      }
      else
      {
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], LOW);
        delay(100);
        i = 7;
        lcd.clear();
        lcd.print(i);
        digitalWrite(LEDS[i], HIGH);
      }
  }
}
