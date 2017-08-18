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
volatile int*** enemies;
volatile int MAX_ENEMY_MOVE = 4;
volatile int MAX_ENEMY = 8;
volatile bool endGame = false;
volatile int enemyShotSpeed = 1;
volatile int globalScore = 0;
volatile int gameLevel = 0;
int hitted = 0;
volatile long randNumber;
volatile int MAX_ENEMY_ROW = 1;
void setup() {
  lcd.begin();
  long seed = 0;
 for (int i = 0; i < 12; i++)
 seed += analogRead(i);
 randomSeed(seed);
 
  Timer4.attachInterrupt(shotPosition);
  Timer4.start(21000);
  Timer5.attachInterrupt(enemyPosition);
  Timer5.start(1250000);
  Timer6.attachInterrupt(enemyShotEnabler);
  Timer6.start(1200000);
  Timer7.attachInterrupt(enemyShot);
  Timer7.start(22500);
  Timer3.attachInterrupt(printScore);
  Timer3.start(125000);
  oled.begin();
  for (int i = 0 ; i < 7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  current_position = new volatile int*[7];
  for(int i = 0; i < 7; ++i)
    current_position[i] = new volatile int[0];


enemyStrategy();
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
  
}
void initializeEnemies() {
  enemies = new volatile int**[MAX_ENEMY_ROW];
  for(int x = 0; x < MAX_ENEMY_ROW; ++x) {
      enemies[x] = new volatile int*[MAX_ENEMY];
      for(int y = 0; y < MAX_ENEMY; ++y) {
          enemies[x][y] = new volatile int[3];
          for(int z = 0; z < 2; ++z) { // initialize the values to whatever you want the default to be
              enemies[x][y][z] = 0;
          }
      }
  }
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
    for(int j = 0 ; j < MAX_ENEMY_ROW; j++){
  for(int i = 0 ; i < MAX_ENEMY; i++){
  if(enemies[j][i][2]){
    renderEnemyShip(enemies[j][i][0],enemies[j][i][1],true);
//    oled.writeRect(enemies[j][i][0], enemies[j][i][1], 8, 8, true);
  }else{
    renderEnemyShip(enemies[j][i][0],enemies[j][i][1],false);
//    oled.writeRect(enemies[j][i][0], enemies[j][i][1], 8, 8, false);

  }
  
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


void printScore() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Score:");
  lcd.setCursor(7,0);
  lcd.print(globalScore);
  lcd.setCursor(11,0);
  lcd.print("lvl:");
  lcd.setCursor(15,0);
  lcd.print(gameLevel);
  if(endGame) {
    lcd.setCursor(0,1);
    lcd.print("LOSER");
  }
}

void renderPlayerShip() {
  for(int i = -2; i < 5; ++i){
    current_position[i+2][0] = player_x + i;
  }
}

void moveShipLeft(){
  int difference = millis()-last_change_time;
       if(player_x > 6 && (((difference)>timeout) || last_change_time == 0)){  
          player_x -= 6;
        last_change_time = millis();
     }
     renderPlayerShip();
}
void moveShipRight(){
  int difference = millis()-last_change_time;
     if(player_x < 119 && (((difference)>timeout) || last_change_time == 0)){
      player_x += 6;
      last_change_time = millis();
     }
     renderPlayerShip();
}

void shot() {
  if(!shotEnable){
    int shotPos = current_position[3][0];
    currentShotPosition[0] = current_position[3][0];
    currentShotPosition[1] = 63;
    shotEnable = true;
  }
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
 for(int j = 0 ; j < MAX_ENEMY_ROW; j++){
  for(int i = 0 ; i < MAX_ENEMY; i++){
    if(posx >= enemies[j][i][0] && posx <= enemies[j][i][0]+8 && posy >= enemies[j][i][1] && posy <= enemies[j][i][1]+8 && enemies[j][i][2] && shotEnable){
      enemies[j][i][2] = false;
      hitted++;
      globalScore++;
      shotEnable = false;
      Serial.println(hitted);
      if(hitted == MAX_ENEMY*MAX_ENEMY_ROW){
        updateLvl();
        int hitted = 0;
      }
    }
  }
 }
  
}
void enemyShot() {
  if(enemyShotEnable) {
      (*(currentEnemyShotPosition+1))+=enemyShotSpeed;
      if((*(currentEnemyShotPosition+1)) > 64){
        enemyShotEnable = false;
      }
      if((*(currentEnemyShotPosition+1)) >= 63 && ((*(currentEnemyShotPosition)) <= player_x+4 && (*(currentEnemyShotPosition)) >= player_x-3)){
        endGame = true;
      }
  }
}
void enemyShotEnabler() {
  for(int j = 0 ; j < MAX_ENEMY_ROW; j++){
  for(int i = 0 ; i < MAX_ENEMY; i++){
    randNumber = random(10);
    if(randNumber>5 && !enemyShotEnable){
      if(enemies[j][i][2] == true){
        enemyShotEnable = true;
        (*(currentEnemyShotPosition+1)) = enemies[j][i][1]+8;
        (*(currentEnemyShotPosition)) = enemies[j][i][0]+4;
      }
    }
  }
  }
}
void enemyPosition() { 
  enemyMoveFlag = !enemyMoveFlag;
  for(int j = 0 ; j < MAX_ENEMY_ROW; j++){
    for(int i = 0 ; i < MAX_ENEMY; i++){
      if(enemyMoveFlag)
        enemies[j][i][0] = enemies[j][i][0] + MAX_ENEMY_MOVE;//(MAX_ENEMY_MOVE>0) ? MAX_ENEMY_MOVE : 0;
      else
        enemies[j][i][0] = enemies[j][i][0] - MAX_ENEMY_MOVE;//(MAX_ENEMY_MOVE>0) ? MAX_ENEMY_MOVE : 0; 
      if(enemies[j][i][1] < 56){
        (MAX_ENEMY_MOVE>0) ? (enemies[j][i][1]++) : 0;
//        enemies[j][i][1]++;
      }else {
        endGame = true;
        break;
      }
    }
  }
}

void updateLvl() {
  enemyShotEnable = false;
  shotEnable = false;
  hitted = 0;
  gameLevel++;
  if(gameLevel < 4){
    MAX_ENEMY_ROW++;
    MAX_ENEMY_MOVE--;
  }
  enemyStrategy();
  
}

void enemyStrategy() {
  initializeEnemies();
  for(int j = 0 ; j < MAX_ENEMY_ROW; j++){
    for(int i = 0 ; i < MAX_ENEMY; i++){
      enemies[j][i][0] = 7+i*15;
      enemies[j][i][1] = 2 + j*12 ;
      enemies[j][i][2] = true;
    }
  }
}

void renderEnemyShip(int x, int y,bool flag){
 // oled.setPixel(x, y, flag);
  oled.setPixel(x+1, y, flag);
 // oled.setPixel(x+2, y, true);
//  oled.setPixel(x+3, y, true);
//  oled.setPixel(x+4, y, true);
//  oled.setPixel(x+5, y, true);
  oled.setPixel(x+6, y, flag);
//  oled.setPixel(x+7, y, true);
  
//  oled.setPixel(x, y+1, true);
//  oled.setPixel(x+1, y+1, true);
  oled.setPixel(x+2, y+1, flag);
//  oled.setPixel(x+3, y+1, true);
//  oled.setPixel(x+4, y+1, true);
  oled.setPixel(x+5, y+1, flag);
//  oled.setPixel(x+6, y+1, true);
//  oled.setPixel(x+7, y+1, true);
  
//  oled.setPixel(x, y+2, true);
  oled.setPixel(x+1, y+2, flag);
  oled.setPixel(x+2, y+2, flag);
  oled.setPixel(x+3, y+2, flag);
  oled.setPixel(x+4, y+2, flag);
  oled.setPixel(x+5, y+2, flag);
  oled.setPixel(x+6, y+2, flag);
//  oled.setPixel(x+7, y+2, true);

  oled.setPixel(x, y+3, flag);
  oled.setPixel(x+1, y+3, flag);
//  oled.setPixel(x+2, y+3, true);
  oled.setPixel(x+3, y+3, flag);
  oled.setPixel(x+4, y+3, flag);
//  oled.setPixel(x+5, y+3, true);
  oled.setPixel(x+6, y+3, flag);
  oled.setPixel(x+7, y+3, flag);

  oled.setPixel(x, y+4, flag);
  oled.setPixel(x+1, y+4, flag);
//  oled.setPixel(x+2, y+4, true);
  oled.setPixel(x+3, y+4, flag);
  oled.setPixel(x+4, y+4, flag);
//  oled.setPixel(x+5, y+4, true);
  oled.setPixel(x+6, y+4, flag);
  oled.setPixel(x+7, y+4, flag);

    oled.setPixel(x, y+5, flag);
  oled.setPixel(x+1, y+5, flag);
  oled.setPixel(x+2, y+5, flag);
  oled.setPixel(x+3, y+5, flag);
  oled.setPixel(x+4, y+5, flag);
  oled.setPixel(x+5, y+5, flag);
  oled.setPixel(x+6, y+5, flag);
  oled.setPixel(x+7, y+5, flag);

//    oled.setPixel(x, y+6, true);
  oled.setPixel(x+1, y+6, flag);
  oled.setPixel(x+2, y+6, flag);
  oled.setPixel(x+3, y+6, flag);
  oled.setPixel(x+4, y+6, flag);
  oled.setPixel(x+5, y+6, flag);
  oled.setPixel(x+6, y+6, flag);
//  oled.setPixel(x+7, y+6, true);

//    oled.setPixel(x, y+7, true);
//  oled.setPixel(x+1, y+7, true);
  oled.setPixel(x+2, y+7, flag);
//  oled.setPixel(x+3, y+7, true);
//  oled.setPixel(x+4, y+7, true);
  oled.setPixel(x+5, y+7, flag);
//  oled.setPixel(x+6, y+7, true);
//  oled.setPixel(x+7, y+7, true);
}

