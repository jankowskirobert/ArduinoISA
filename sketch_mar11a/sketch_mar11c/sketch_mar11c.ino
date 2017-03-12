#include <ISADefinitions.h>
#include <ISAButtons.h>
#include <ISALiquidCrystal.h>

ISALiquidCrystal lcd;
ISAButtons button;

void setup() {
  lcd.begin();
  lcd.clear();
  for(int i = 0; i < 8; i++)
    pinMode(LEDS[i], OUTPUT);
  button.init();
  digitalWrite(LEDS[0], HIGH);
}

int i = 0;

void loop() {
  
  if(button.buttonPressed(1))
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
  
  if(button.buttonPressed(0))
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
