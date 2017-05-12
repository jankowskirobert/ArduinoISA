#include <ISADefinitions.h>
#include <ISALedControl.h>
#include <ISALiquidCrystal.h>
#include <ISAButtons.h>
#include <ISAOLED.h>

ISAOLED oled;
ISALiquidCrystal lcd;
ISALedControl led;
ISAButtons button;
int joy1_x = 0;
int joy1_y = 0;
int pixel[][2]  = {{0,0},{0,0}};
volatile int** current_position;
bool leftButtonState = false;
bool rightButtonState = false;
unsigned long start_time_LEFT;
unsigned long start_time_RIGHT;
volatile long long timeout = 200; // 3 seconds
volatile long long last_change_time = 0;

//volatile enemies[][2] = {{}};

void setup() {
  oled.begin();
  for (int i = 0 ; i < 7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  current_position = new volatile int*[3];
  for(int i = 0; i < 3; ++i)
    current_position[i] = new volatile int[0];
    
  current_position[0][0] = 62; 
  current_position[0][1] = 63; 
  current_position[1][0] = 63; 
  current_position[1][1] = 63; 
  current_position[2][0] = 64; 
  current_position[2][1] = 63; 
  current_position[3][0] = 63; 
  current_position[3][1] = 62; 
  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
   
  button.init();
  oled.gotoXY(2,2);
  oled.print("hello"); 
  Serial.begin(9600);
  Serial.println("Hello World");
  oled.renderAll();
   for(int i = 0; i < 3 ;i++){
     oled.setPixel(current_position[i][1], current_position[i][0], true);
  }
  attachInterrupt(digitalPinToInterrupt(KEY_LEFT), moveShipLeft, FALLING);  
  attachInterrupt(digitalPinToInterrupt(KEY_RIGHT), moveShipRight, FALLING);
  start_time_LEFT = millis();
  start_time_RIGHT = millis();
   delay(1000);
}

void loop() {



   for(int i = 0; i < 3 ;i++){
     oled.setPixel(current_position[i][1], current_position[i][0], true);
         if(button.buttonPressed(15)){
    shot();

  }
        oled.renderAll();
 }
  //oled.setPixel(current_position[3][1], current_position[3][0], true);
      oled.renderAll();
 delay(100);

 oled.clear(false);

}


void moveShipLeft(){
  int difference = millis()-last_change_time;
       if(current_position[1][0] > 1 && (((difference)>timeout) || last_change_time == 0)){
        current_position[0][0] -= 1;
        current_position[1][0] -= 1;
        last_change_time = millis();
     }
}
void moveShipRight(){
  int difference = millis()-last_change_time;
     if(current_position[0][0] < 6 && (((difference)>timeout) || last_change_time == 0)){
      current_position[0][0] += 1;
      current_position[1][0] += 1;
      last_change_time = millis();
     }
}

void shot() {
  int shotPos = current_position[1][0];
  for(int i = 6; i >= 0 ; i--){
    oled.setPixel(i, shotPos, true);
    delay(35);
    oled.setPixel(i, shotPos, false);
    oled.renderAll();
  }
  
}

void remapToDisplay(int angIn_X, int angIn_Y, int barrier_x, int barrier_y){
  led.clearDisplay();
  lcd.clear();
  int tmp_x = map(angIn_X, 0, 1015, 7 ,0);
  
  lcd.setCursor(0,0);
  lcd.print("J1X:");
  lcd.setCursor(5,0);
  lcd.print(tmp_x);
  lcd.setCursor(0,1);
  lcd.print(angIn_X);

  int tmp_y = map(angIn_Y, 40, 1015, 7 ,0);
  
  lcd.setCursor(10,0);
  lcd.print("J1Y:");
  lcd.setCursor(15,0);
  lcd.print(tmp_y);
  lcd.setCursor(10,1);
  lcd.print(angIn_Y);

  int val = map(tmp_x, 0, 8, 0, 255);
  ledBright(val);

  pixelUpdate(pixel, tmp_x,tmp_y);
//  led.setLed(tmp_y, tmp_x, true);
}

void ledBright(int val){
  analogWrite(LEDS[1], val);
}

void barrier(int x, int y) {
  led.setLed(y, x, true);
}

void pixelUpdate(int pixel[][2], int x, int y) {
  
    pixel[0][0] = x-1 ;
    pixel[0][1] = y-1; 
    
    pixel[1][0] = x ;
    pixel[1][1] = y-1 ;
    
//    pixel[2][0] = x-1; 
//    pixel[2][1] = y ;
//
//    pixel[3][0] = x ;
//    pixel[3][1] = y; 
  for(int i = 0; i < 4 ;i++){
     led.setLed(pixel[i][1], pixel[i][0], true);
    }
}


