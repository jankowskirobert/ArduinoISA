#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
}
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
  int j=i/60;
  int k=i%60;
  if(j>9)
    lcd.print(j);
  else{
    lcd.print("0");
    lcd.print(j);
  }
  lcd.print(":");
  if(k>9)
    lcd.print(k);
  else{
    lcd.print("0");
    lcd.print(k);
  }
  
  i++;
  delay(1000);
  lcd.clear();
  
}
