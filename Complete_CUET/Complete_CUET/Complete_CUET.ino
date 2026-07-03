// Asif Bin Sayed 
// Department of Electrical and Electronics 
//Dhaka University of Engineeering and Technology 

#include <EEPROM.h>
#define BlackSerface 1 // 1 for white line && 0 for black line
#define MX motor(baseSpeed , baseSpeed);
#define TEST(x) \
  MX delay(x); \
  sensorRead();

//==================Sensor Array===================
int sen[8], onBlack;
const int senArrPin[8] = { A0, A1, A2, A3, A4, A5, A6, A7 };
long int Read = 0, lastRead = 0, bigRead = 0;
int ref[8];

int smin[8] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 }, smax[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, i, l;

int leftWheel, rightWheel;
//==================Motor Driver Pin===================
const int inA = 4, inB = 2, inC = 3, inD = 5;
int lastSpeedL, lastSpeedR;
int leftSign, rightSign;

//==================Button=============================
const int buttonPin = 8;
const int bazzer = A10;
const int led = 12;
#define R_LED 13
#define G_LED 11
#define reverseMethode false
int stringLength = 0;

//=================PID Variable========================
float Ki = 0, Kd = 2750, baseSpeed = 255, MaxSpeed = 255, setPoint = 4.5, ForMax = 4.5;
float Kp = 100, position = 0, error = 0, lastError = 0, P = 0, I = 0, D = 0, PID = 0, leftPID = 0, rightPID = 0;
//(MaxSpeed + baseSpeed) / ForMax
//=================Algorithum Rule==========================
const String leftRule[7][2] = { { "LBR", "B" }, { "LBS", "R" }, { "LBL", "S" }, { "SBL", "R" }, { "SBS", "B" }, { "RBL", "B" } };
const String rightRule[7][2] = { { "RBL", "B" }, { "RBS", "L" }, { "RBR", "S" }, { "SBR", "L" }, { "SBS", "B" }, { "LBR", "B" } };
 char dir = 'R'; // suitable direction; Left == L & Right == R  % changed const
String path = "";
int which_round = 0;  // 0 for 1st round and 1 for second round
int Turn = 0;

//=================General Variable===================
int nintyDegDelay = 60, turnSpeed = 180, mazeSolve = false, scan = true, angle45 = false, pathCount = 0, Break = 110, L_Delay = 30;

String get;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++)
    pinMode(senArrPin[i], INPUT);

  pinMode(buttonPin, INPUT);
  pinMode(bazzer, OUTPUT);
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);

  // if (dir == 'R') {
  //   leftSign = 1;
  //   rightSign = -1;
  // } else if (dir == 'L') {
  //   leftSign = -1;
  //   rightSign = 1;
  // }

  if (digitalRead(buttonPin)) {
    digitalWrite(R_LED, HIGH);
    delay(400);
    autoCal();
   digitalWrite(R_LED, LOW);
  }

  for (int i = 0; i < 8; i++) {
    EEPROM.get(i * 2, ref[i]);
  }
  
  digitalWrite (G_LED, HIGH);
  delay(3000);
  if(digitalRead(buttonPin))
{ 
  digitalWrite(R_LED,HIGH);
dir = 'L';
}
delay(1000);



  while (digitalRead(buttonPin) != HIGH) {
    delay(10);
  }
  delay(400);


   
  }
}



void loop() {
  sensorRead();

  if (!Read) {
    TEST(5);
    if (!Read) {
      TEST(5)
      if (!Read) {
        white();
      }
    }
  }

  else if (blackCondition()) {
    TEST(1);
    if (blackCondition()) {
      TEST(1);
      if (blackCondition()) {
        turnLeft();
      }
    }
  }

  else if (left90()) {
    TEST(1);
    if (left90()) {
      TEST(1);
      if (left90()) {
        turnLeft();
      }
    }
  }

  else if (right90()) {
    TEST(1);
    if (right90()) {
      TEST(1);
      if (right90()) {
        turnRight();
      }
    }
  }

  else
    onLinePID();
}
