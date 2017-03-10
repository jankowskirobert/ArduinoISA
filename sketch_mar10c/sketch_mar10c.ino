#include <LiquidCrystal.h>
#include "Buttons.h" 
Buttons button ;
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
int operationSign = 0;
int present = 0;
int past = 0;
int value = 0;
void setup() {
  Serial.begin(9600);
 lcd.begin(16,2);
  lcd.print("     DUPA");
   button.init();
}

void loop() {


  if (button.buttonPressed(0)) {
    //7 
    value = value*10 + 7;
    lcd.setCursor(0, 0);
    lcd.print(7);
 }
 
if (button.buttonPressed(1)) {
value = value*10 + 8;
lcd.setCursor(0, 0);
lcd.print(8);
 }
   if (button.buttonPressed(2)) {
value = value*10 + 9;
lcd.setCursor(0, 0);
lcd.print(9);
 }
   if (button.buttonPressed(7)) {
value = value*10 + 4;
lcd.setCursor(0, 0);
lcd.print(4);
 }
    if (button.buttonPressed(6)) {
value = value*10 + 5;
lcd.setCursor(0, 0);
lcd.print(5);
 }
    if (button.buttonPressed(5)) {
value = value*10 + 6;
lcd.setCursor(0, 0);
lcd.print(6);
 }
    if (button.buttonPressed(8)) {
value = value*10 + 1;
lcd.setCursor(0, 0);
lcd.print(1);
 }
    if (button.buttonPressed(9)) {
value = value*10 + 2;
lcd.setCursor(0, 0);
lcd.print(2);
 }
    if (button.buttonPressed(10)) {
value = value*10 + 3;
lcd.setCursor(0, 0);
lcd.print(3);
 }
     if (button.buttonPressed(15)) {
value = 0;
past = 0;
lcd.clear();
 }
     if (button.buttonPressed(14)) {
value = value*10;
lcd.setCursor(0, 0);
lcd.print(0);
 }
 
     if (button.buttonPressed(13)) {
  
  lcd.setCursor(0, 1);
  int result = 0;
  Serial.print("PAST: "); 
  Serial.print(past);
  Serial.println();
  Serial.print("VALUE: "); 
Serial.print(value);
Serial.println();
  result = doMath();
  Serial.println(result);
  lcd.print(result);  
  
  past = result;
  value = 0;
  // calc
 }
     if (button.buttonPressed(3)) {
operationSign = 3;
past = value;
value = 0;
lcd.setCursor(0, 0);
lcd.print("/");
 }
 if (button.buttonPressed(4)) {
operationSign = 2;
past = value;
value = 0;
lcd.setCursor(0, 0);
lcd.print("*");

 }
  if (button.buttonPressed(11)) {
    operationSign = 1;
    past = value;
    value = 0;
    lcd.setCursor(0, 0);
    lcd.print("-");
 }
  if (button.buttonPressed(12)) {
    operationSign = 0;
    past = value;
    value = 0;
    lcd.setCursor(0, 0);
    lcd.print("+");
 }
  delay(25);
}
int doMath(){
  switch (operationSign){
    case 0:
      return past + value;
    case 1:
      return past - value;
    case 2:
      return past * value;
    case 3:
      return past / value;

  }
}


