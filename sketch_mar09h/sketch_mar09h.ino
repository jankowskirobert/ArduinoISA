long randNumber;
int randomValues[8];
void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 randomSeed(analogRead(0));
 initArray();
 displayLED();
 sortBubble();

}

void sortBubble() {
    int maxValue = 0;
    int tmp = 0;
    int i= 0;
    bool isChanged = true;
    while(isChanged){
      isChanged = false;
      for(i = 0; i<7;i++ ){
        if(randomValues[i] > randomValues[i+1]) {
          tmp = randomValues[i];
          randomValues[i] = randomValues[i+1];
          randomValues[i+1] = tmp;
          isChanged = true;
        } 
        displayLED();
        delay(1000);
      }
    }
}

void displayLED() {
  int i = 0;
  for(i = 0 ; i < 8 ;i++){
    analogWrite(i+2, randomValues[i] );
  }
}

void initArray(){
  int i = 0;
  for(i = 0; i<8;i++ ){
    randomValues[i] = random(60);
  }
}

void loop(){}
