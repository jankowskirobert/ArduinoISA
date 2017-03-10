#include <LiquidCrystal.h>
#include <DueTimer.h>
#include "Buttons.h" 
Buttons button ;
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
String menuOptions[] = {
  "Menu option 1",
  "Menu option 2",
  "Menu option 3"
};
bool observerState = false;
int currentMenuPosition = 0;
int choosedPosition = -1;
void setup() {
    button.init();
    lcd.begin(16,2);
    initScreen();
    printMenuPosition(1);
    pinMode(46, INPUT);
    pinMode(47, INPUT);
    pinMode(49, INPUT);
    attachInterrupt(digitalPinToInterrupt(47), key_up, FALLING);
    attachInterrupt(digitalPinToInterrupt(49), key_down, FALLING);

    attachInterrupt(digitalPinToInterrupt(46), key_right, FALLING);
}

void loop() {

   if (button.buttonPressed(14)) {
    currentMenuPosition = 0; 
    observerState = true;
   }
   if (button.buttonPressed(8)) {
    currentMenuPosition = 1; 
    observerState = true;
   }
   if (button.buttonPressed(9)) {
    currentMenuPosition = 2; 
    observerState = true;
   }
   delay(25);
   printMenuPosition(currentMenuPosition);
}
void printMenuPosition(int menuPosition) {
  if(observerState){
    noInterrupts();
    clearMenuPosition();
    lcd.setCursor(0,1);
    lcd.print(menuOptions[menuPosition]);
    interrupts();
  }
}
void initScreen(){
  lcd.clear();
  lcd.print("MENU");

}
void clearMenuPosition(){
  int i = 0;
  lcd.setCursor(0,1);
  for(i = 0; i<menuOptions[currentMenuPosition].length() ;i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }
  observerState = false;
}
void key_up() {
  observerState = true;
  if(currentMenuPosition < 2)
    currentMenuPosition++;
  else
    currentMenuPosition = 0;
}
void key_down(){
  observerState = true;
  if(currentMenuPosition > 0)
    currentMenuPosition--;
  else
    currentMenuPosition = 2;
}
void key_right () {
  choosedPosition = currentMenuPosition;
  lcd.setCursor(4,0);
  if(choosedPosition >-1){
    String out = " Selected=";
    lcd.print(out);
    lcd.setCursor(out.length()+4,0);
    lcd.print(choosedPosition+1);
  }
}

