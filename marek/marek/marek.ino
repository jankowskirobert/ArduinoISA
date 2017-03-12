#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=0;
int j=0;

void setup() {
  lcd.begin();

}

void loop() {

  if(i==60){
    j++;
    i=0;
  }
  if(j<10)
  {
  lcd.print("0");
  lcd.print(j);
  }
  else lcd.print(j);

  
  lcd.print(":");

  if(i<10)
  {
  lcd.print("0");
  lcd.print(i);
  }
  else lcd.print(i);
  delay(1000);
  i++;
  lcd.clear();

}
