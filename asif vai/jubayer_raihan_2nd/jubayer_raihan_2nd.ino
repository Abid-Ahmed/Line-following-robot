#include <EEPROM.h>

#define MX motor(baseSpeed, baseSpeed);
#define TEST(x) \
  MX delay(x); \
  sensorRead();

int BlackSerface = 0;
int sen[8];
int ArrPin[8] =  { A0, A1, A2, A3, A4, A5, A6, A7 };
int ref[8] = { 500, 500, 500, 500, 500, 500, 500, 500 };
int smin[8] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 }, smax[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
long int Read = 0;
int blackConditionCounter = 1;

// Pin definitions as requested
#define A1 10
#define A2 11
#define B1 8
#define B2 9
#define buttonPin 2

int LSpeed, RSpeed, onBlack, Left, Right, turnSpeed = 200, Delay = 150,GapDelay = 100, ADelay = 180, Error = false;
float Ki = 0, Kd = 500, baseSpeed = 100, MaxSpeed = 250, setPoint = 4.5, ForMax = 4;
float Kp = 30, position = 0, error = 0, lastError = 0, P = 0, I = 0, D = 0, PID = 0, leftPID = 0, rightPID = 0;
char PlusDir = 'L', dir = 'R';

void setup() {
  Serial.begin(9600);
  
  // Sensor pin declarations
  for (int i = 0; i < 8; i++)
    pinMode(ArrPin[i], INPUT);
  
  // Motor pin declarations
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  delay(300);

  if (digitalRead(buttonPin) == LOW) {
    delay(500);
    autoCal();
  }
  delay(500);
  autoCal();
  for (int i = 0; i < 8; i++) {
    EEPROM.get(i * 2, ref[i]);
  }

  while (digitalRead(buttonPin) == HIGH) {
    delay(10);
  }
  delay(400);
}

void loop() {
// for (int i = 0; i < 8; i++){
// Serial.print(" Sen");
// Serial.print(ArrPin[i]);
// Serial.print(" ");
// Serial.print(analogRead(ArrPin[i])) ;
// Serial.println(" ");
// delay(500);
// }
// return;

  sensorRead();
  // delay(400);
  // return;

  if (!Read) {
    TEST(10);
    if (!Read)
      whiteAction();
  }
 else if (Read == 12300678 || Read == 12340678 || Read == 12305678) {

    BlackSerface = !BlackSerface;
    return;
  }

  else if (left90()) {
    TEST(5);
    if (left90()) {
      TEST(5);
      if (left90()) {
        turnLeft();
      }
    }
  }
  else if (right90()) {
    TEST(5);
    if (right90()) {
      TEST(5);
      if (right90()) {
        turnRight();
      }
    }
  }
  else if (left45()) {
    TEST(2);
    if (left45()) {
      TEST(2);
      if (left45()) {
        turnLeft45();
      }
    }
  }
  else if (right45()) {
    TEST(2);
    if (right45()) {
      TEST(2);
      if (right45()) {
        turnRight45();
      }
    }
  }
  else if (starCondition() == true) {
    TEST(5)
    if (starCondition() == true) {
      TEST(5)
      if (starCondition() == true) {
        starAction();
      }
    }
  }

 else if (Tcondition()) {
    TEST(10);
    if (Tcondition()) {
      TEST(10);
      if (Tcondition()) {
        turnLeft();
      }
    }
  } 


 else if (plusCondition()) {
    TEST(5);
    if (plusCondition()) {
      TEST(5);
      if (plusCondition()) {
        ENDCondition();
      }
    }
  } 

  
// Add this at the top with other global variables

else if (blackCondition()) {
  TEST(10);
  if (blackCondition()) {
    TEST(10);
    if (blackCondition()) {
      ENDCondition();
    }
  }
}
//  else if (whiteCondition()) {
//     TEST(10);
//     if (whiteCondition()) {
//       TEST(10);
//       if (whiteCondition()) {
//         motor(0,0);
//         delay(7000);
//         motor(baseSpeed,baseSpeed);
//       }
//     }
//   } 
  else {
    onLinePID();
  }
}

