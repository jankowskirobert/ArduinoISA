#include <ISADefinitions.h>
#include <ISALedControl.h>
#include <ISALiquidCrystal.h>
#include <ISAButtons.h>
#include <ISAOLED.h>
#include <DueTimer.h>

ISAOLED oled;
ISALiquidCrystal lcd;
ISALedControl led;
ISAButtons button;
int joy1_x = 0;
int joy1_y = 0;
int currentShotPosition[2]  = {0,0};
int currentEnemyShotPosition[2]  = {0,0};
volatile int** current_position;
bool leftButtonState = false;
bool rightButtonState = false;
unsigned long start_time_LEFT;
unsigned long start_time_RIGHT;
volatile long long timeout = 200; // 3 seconds
volatile long long last_change_time = 0;
bool shotEnable = false;
bool enemyShotEnable = false;
bool enemyMoveFlag = false;
volatile int** enemies;
volatile int MAX_ENEMY_MOVE = 4;
volatile int MAX_ENEMY = 8;
volatile bool endGame = false;
int hitted = 0;
volatile long randNumber;

void setup() {
  long seed = 0;
 for (int i = 0; i < 12; i++)
 seed += analogRead(i);
 randomSeed(seed);
 
  Timer4.attachInterrupt(shotPosition);
  Timer4.start(25000);
  Timer5.attachInterrupt(enemyPosition);
  Timer5.start(1250000);
  Timer6.attachInterrupt(enemyShotEnabler);
  Timer6.start(1200000);
  Timer7.attachInterrupt(enemyShot);
  Timer7.start(22500);
  oled.begin();
  for (int i = 0 ; i < 7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  current_position = new volatile int*[7];
  for(int i = 0; i < 7; ++i)
    current_position[i] = new volatile int[0];

  enemies = new volatile int*[8];
  for(int i = 0; i < MAX_ENEMY; ++i)
    enemies[i] = new volatile int[0];
    
  current_position[0][0] = 60; 
  current_position[0][1] = 63;
   
  current_position[1][0] = 61; 
  current_position[1][1] = 63;
   
  current_position[2][0] = 62; 
  current_position[2][1] = 63; 
  
  current_position[3][0] = 63; 
  current_position[3][1] = 63; 
     
  current_position[4][0] = 64; 
  current_position[4][1] = 63;
   
  current_position[5][0] = 65; 
  current_position[5][1] = 63; 
  
  current_position[6][0] = 66; 
  current_position[6][1] = 63; 
    
  
  pinMode(KEY_LEFT, INPUT);
  pinMode(KEY_RIGHT, INPUT);
   
  button.init();
  oled.gotoXY(2,2);
  oled.print("hello and die"); 
  Serial.begin(9600);
  Serial.println("Hello World");
  oled.renderAll();
   for(int i = 0; i < 3 ;i++){
     oled.setPixel(current_position[i][0], current_position[i][1], true);
  }
  attachInterrupt(digitalPinToInterrupt(KEY_LEFT), moveShipLeft, FALLING);  
  attachInterrupt(digitalPinToInterrupt(KEY_RIGHT), moveShipRight, FALLING);
  start_time_LEFT = millis();
  start_time_RIGHT = millis();
   delay(1000);
  enemyStrategy();
}
volatile int player_x = 63;
int joyX = 0;
void loop() {
   joyX = map(analogRead(A1), 1, 1023, 2, -3);
   
   if((player_x<=127) && (player_x>=1)) {    
        player_x = player_x + joyX/2;
      }
      if(player_x > 127) {
        player_x = 127;
      }
      else if(player_x < 1) {
        player_x = 1;
      }
  
renderPlayerShip();
      
    
  if(!endGame){
  for(int i = 0 ; i < MAX_ENEMY; i++){
  if(enemies[i][2]){
    oled.writeRect(enemies[i][0], enemies[i][1], 8,8,true);
  }else{
    oled.writeRect(enemies[i][0], enemies[i][1], 8,8,false);

  }
}
   for(int i = 0; i < 7 ;i++){
     oled.setPixel(current_position[i][0], current_position[i][1], true);

    }

  oled.renderAll();
  if(button.buttonPressed(15)){
    shot();
  }

if(shotEnable){
    oled.setPixel(currentShotPosition[0], currentShotPosition[1], true);
        oled.renderAll();
           oled.setPixel(currentShotPosition[0], currentShotPosition[1]-1, false);
           oled.renderAll();
}
if(enemyShotEnable){
    oled.setPixel(currentEnemyShotPosition[0], currentEnemyShotPosition[1], true);
        oled.renderAll();
           oled.setPixel(currentEnemyShotPosition[0], currentEnemyShotPosition[1]-1, false);
           oled.renderAll();
}
 oled.clear(false);
    } else {
      oled.clear(true);
    }
}




void renderPlayerShip() {
  for(int i = -2; i < 5; ++i){
    current_position[i+2][0] = player_x + i;
  }
}

void moveShipLeft(){
  int difference = millis()-last_change_time;
       if(player_x > 3 && (((difference)>timeout) || last_change_time == 0)){  
          player_x -= 3;
        last_change_time = millis();
     }
     renderPlayerShip();
}
void moveShipRight(){
  int difference = millis()-last_change_time;
     if(player_x < 122 && (((difference)>timeout) || last_change_time == 0)){
      player_x += 3;
      last_change_time = millis();
     }
     renderPlayerShip();
}

void shot() {
  int shotPos = current_position[3][0];
  currentShotPosition[0] = current_position[3][0];
  currentShotPosition[1] = 63;
  shotEnable = true;
  
  
}

void shotPosition(){
  if(shotEnable) {
      (*(currentShotPosition+1))--;
      checkShot((*(currentShotPosition)),(*(currentShotPosition+1)));
      if((*(currentShotPosition+1)) <= 0){
        shotEnable = false;
      }
  }
}

void checkShot(int posx, int posy){
 
  for(int i = 0 ; i < MAX_ENEMY; i++){
    if(posx >= enemies[i][0] && posx <= enemies[i][0]+8 && posy <= enemies[i][1] && posy <= enemies[i][1]+8 && enemies[i][2]){
      enemies[i][2] = false;
      hitted++;
      Serial.println(hitted);
      if(hitted == MAX_ENEMY){
        endGame = true;
         int hitted = 0;
      }
    }
  }
  
}
void enemyShot() {
  if(enemyShotEnable) {
      (*(currentEnemyShotPosition+1))++;
      if((*(currentEnemyShotPosition+1)) > 64){
        enemyShotEnable = false;
      }
      if((*(currentEnemyShotPosition+1)) >= 64 && ((*(currentEnemyShotPosition)) <= player_x+4 && (*(currentEnemyShotPosition)) >= player_x-3)
      ){
        endGame = true;
      }
  }
}
void enemyShotEnabler() {
  randNumber = random(MAX_ENEMY-1);
  if(enemies[randNumber][2] == true){
    enemyShotEnable = true;
    (*(currentEnemyShotPosition+1)) = enemies[randNumber][1]+8;
    (*(currentEnemyShotPosition)) = enemies[randNumber][0]+4;
  }
}
void enemyPosition() {
  
  
  enemyMoveFlag = !enemyMoveFlag;
  for(int i = 0 ; i < MAX_ENEMY; i++){
    if(enemyMoveFlag)
      enemies[i][0] = enemies[i][0] + MAX_ENEMY_MOVE;
    else
      enemies[i][0] = enemies[i][0] - MAX_ENEMY_MOVE; 
    enemies[i][1]++;
  }
}

void enemyStrategy() {
  for(int i = 0 ; i < MAX_ENEMY; i++){
    enemies[i][0] = 7+i*15;
    enemies[i][1] = 2;
    enemies[i][2] = true;
  }

}

