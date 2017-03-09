
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  }

void loop() {
//  pairTurnOn(2,3,500);
//  delay(100);
//  pairTurnOn(4,5,250);
//  delay(100);
//  pairTurnOn(6,7,100);
//  delay(100);
//  pairTurnOn(8,9,700);
//  delay(100);
  blinkPairs();
}
void binary2LED(unsigned int value) {
  int i = 0;
  int l=2;
  for(;i<8;i++, l++){
    digitalWrite(l, value%2 );
    value/=2;
  }
  
}
void blinkPairs(){
  int p=0;
  int p1,p2,p3,p4=0;
  while(1){
    delay(1000);
    if(!(p%2)) {
      p1=!p1;
      digitalWrite(2,p1);
      digitalWrite(3,!p1);
    }
    if(!(p%4)) {
      p2=!p2;
      digitalWrite(4,p2);
      digitalWrite(5,!p2);
    }
    if(!(p%8)) {
      p3=!p3;
      digitalWrite(6,p3);
      digitalWrite(7,!p3);
    }
    if(!(p%16)) {
      p4=!p4;
      digitalWrite(8,p4);
      digitalWrite(9,!p4);
    }
    p++;
  }

  
  
}

void pairTurnOn(int i, int j, unsigned int del){
        
          digitalWrite(j,HIGH);
        delay(del);
      digitalWrite(j,LOW);
         delay(del);

      digitalWrite(i,HIGH);
            delay(del);
      digitalWrite(i,LOW);

}

