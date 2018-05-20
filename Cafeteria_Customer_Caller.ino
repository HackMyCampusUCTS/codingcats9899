#define segA 2
#define segB 3
#define segC A3
#define segD A4
#define segE A5
#define segF 4
#define segG 5

#define segH 7
#define segI 8
#define segJ 9
#define segK 10
#define segL 11
#define segM 12
#define segN 13

#define joyX A0
#define joyY A1

int countNum = 0;
int xVar = 0;
int yVar = 0;
int button = 0;
int center = 0;

void joyDisplay();
void countDisplay();
void countBlank();

void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(A3, OUTPUT);  
  pinMode(A4, OUTPUT);  
  pinMode(A5, OUTPUT); 
  for (int i = 4; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
}


void loop(){

  xVar = analogRead(joyX);
  yVar = analogRead(joyY);
  button = digitalRead(6);
  
  if (xVar >= 0 && xVar <= 25 && yVar >= 354 && yVar <= 669){
    countNum = 0;
  }
  if (xVar >= 0 &&  xVar <= 130 && yVar >= 0 && yVar <= 353){
    countNum = 1;
  }
  if (xVar >= 131 &&  xVar <= 510 && yVar >= 0 && yVar <= 97){
    countNum = 2;
  }
  if (xVar >= 515 &&  xVar <= 812 && yVar >= 0 && yVar <= 97){
    countNum = 3;
  }
  if (xVar >= 813 &&  xVar <= 1023 && yVar >= 0 && yVar <= 353){
    countNum = 4;
  }
  if (xVar >= 999 &&  xVar <= 1023 && yVar >= 354 && yVar <= 669){
    countNum = 5;
  }
  if (xVar >= 813 &&  xVar <= 1023 && yVar >= 700 && yVar <= 1023){
    countNum = 6;
  }
  if (xVar >= 515 &&  xVar <= 812 && yVar >= 926 && yVar <= 1023){
    countNum = 7;
  }
  if (xVar >= 131 &&  xVar <= 510 && yVar >= 926 && yVar <= 1023){
    countNum = 8;
  }
  if (xVar >= 0 &&  xVar <= 130 && yVar >= 700 && yVar <= 1023){
    countNum = 9;
  }
  if (xVar >= 500 &&  xVar <= 505 && yVar >= 515 && yVar <= 550){
    center++;
    if (center >= 100){
      countNum = 0;
    }
  } else {
    center = 0;
  }
  

  
  joyDisplay();
  if( button == 1){
    countDisplay();
    tone(A2,900);
    delay(300);
    noTone(A2);
    delay(10);
    tone(A2,600);
    delay(300);
    noTone(A2);
    countBlank();
    delay(500);
    countDisplay();
    delay(500);
    countBlank();
    delay(500);
    countDisplay();
    delay(500);
    countBlank();
    delay(500);
    countDisplay();
  }
    
  Serial.print(xVar);
  Serial.print("\t");
  Serial.print(yVar);
  Serial.print("\t");
  Serial.print(button);
  Serial.print("\t");
  Serial.println(countNum);

}

void joyDisplay(){
  switch (countNum){
    case 0:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;
  
    case 1:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  
    case 2:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
  
    case 3:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;
  
    case 4:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  
    case 5:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  
    case 6:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  
    case 7:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;
  
    case 8:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  
    case 9:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;
  }
}

void countBlank(){
  digitalWrite(segH, LOW);
  digitalWrite(segI, LOW);
  digitalWrite(segJ, LOW);
  digitalWrite(segK, LOW);
  digitalWrite(segL, LOW);
  digitalWrite(segM, LOW);
  digitalWrite(segN, LOW);
}

void countDisplay(){
  switch (countNum){
    case 0:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, HIGH);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, LOW);
    break;
  
    case 1:
    digitalWrite(segH, LOW);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, LOW);
    digitalWrite(segL, LOW);
    digitalWrite(segM, LOW);
    digitalWrite(segN, LOW);
    break;
  
    case 2:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, LOW);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, HIGH);
    digitalWrite(segM, LOW);
    digitalWrite(segN, HIGH);
    break;
  
    case 3:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, LOW);
    digitalWrite(segM, LOW);
    digitalWrite(segN, HIGH);
    break;
  
    case 4:
    digitalWrite(segH, LOW);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, LOW);
    digitalWrite(segL, LOW);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, HIGH);
    break;
  
    case 5:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, LOW);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, LOW);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, HIGH);
    break;
  
    case 6:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, LOW);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, HIGH);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, HIGH);
    break;
  
    case 7:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, LOW);
    digitalWrite(segL, LOW);
    digitalWrite(segM, LOW);
    digitalWrite(segN, LOW);
    break;
  
    case 8:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, HIGH);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, HIGH);
    break;
  
    case 9:
    digitalWrite(segH, HIGH);
    digitalWrite(segI, HIGH);
    digitalWrite(segJ, HIGH);
    digitalWrite(segK, HIGH);
    digitalWrite(segL, LOW);
    digitalWrite(segM, HIGH);
    digitalWrite(segN, HIGH);
    break;
  }
}




