#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=0, j=0;
void setup() {
  // put your setup code here, to run once:
 lcd.begin();



}

void loop() {
  // put your main code here, to run repeatedly:
delay(1);
lcd.print(i);
lcd.print(":");
lcd.print(j);
j++;
delay(999);
lcd.clear();
if(j==60){
  j=0;
  i++; 
}

}
