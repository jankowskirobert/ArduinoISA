#include <ISADefinitions.h>
#include <ISALedControl.h>
#include <ISALiquidCrystal.h>
#include <ISAButtons.h>

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
void setup() {
  for (int i = 0 ; i < 7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  current_position = new volatile int*[2];
  for(int i = 0; i < 2; ++i)
    current_position[i] = new volatile int[0];
    
  current_position[0][0] = 3; 
  current_position[0][1] = 7; 
  current_position[1][0] = 4; 
  current_position[1][1] = 7; 

  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
   
  button.init();
  lcd.begin();
  lcd.print("hello world");    
  Serial.begin(9600);
  Serial.println("Hello World");
  lcd.begin();
  led.init();
   for(int i = 0; i < 2 ;i++){
     led.setLed(current_position[i][1], current_position[i][0], true);
  }
  attachInterrupt(digitalPinToInterrupt(KEY_LEFT), moveShipLeft, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(KEY_RIGHT), moveShipRight, CHANGE);
  start_time_LEFT = millis();
  start_time_RIGHT = millis();
}

void loop() {
  
  
    delay(50);
  if(leftButtonState){
    led.clearDisplay();
     if(current_position[0][0] > 0 && current_position[1][0] < 7){
  current_position[0][0] -= 1;
  current_position[1][0] -= 1;
     }
    Serial.println("GO LEFT");
  }
    if(rightButtonState){
    led.clearDisplay();
     if(current_position[0][0] > 0 && current_position[1][0] < 7){
  current_position[0][0] += 1;
  current_position[1][0] += 1;
     }
    Serial.println("GO RIGHT");
  }

   for(int i = 0; i < 2 ;i++){
     led.setLed(current_position[i][1], current_position[i][0], true);
  }
  
}


void moveShipLeft(){
      if(millis() - start_time_LEFT > 150){
        leftButtonState = true;
        start_time_LEFT = millis();
      } else {
        leftButtonState = false;     
      }
}
void moveShipRight(){
      if(millis() - start_time_RIGHT > 150){
        rightButtonState = true;
        start_time_RIGHT = millis();
      } else {
        rightButtonState = false;   
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


