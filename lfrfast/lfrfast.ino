#define M1 11 //pin declar  //2nd round
#define M2 10
#define M3 8
#define M4 9
#define button1 2
#define linedelay 35
#define LMSpeed 11
#define RMSpeed 11
#define maxLR 13
#define maxSpeed 130
#define cs 180
#define delayspeed 180
#define turndelay 10
#define uturndelay 10

bool lap=false;
int tcount=0;
int i;
int x = 0;
long long int t = 0;
bool Rightfound = false;
bool Leftfound = false;
bool inv = false;
int lastSpeedL = 0;
int lastSpeedR = 0;
void calibration();

int value1 = 0, value2 = 0, value3 = 0, value4 = 0, value5 = 0, value6 = 0, value7 = 0, value8 = 0;
int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0;

int s[8], smin[8] = {0, 0, 0, 0, 0, 0, 0, 0}, smax[8] = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};
int ref[8];
float error = 0, lasterror = 0, kp = 81, kd = 1001, line = 0, PD = 0, PID = 0; // kp=115 kd=850
long long int looptime = 0;
long long int tlast = 0;
int lm = LMSpeed;
int rm = RMSpeed;

void setup()
{
pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
    while (digitalRead(button1) == HIGH)
  {
  }
  delay(200);
 calibration();


while (digitalRead(button1) == HIGH)
  {
  }

}
void loop()
{

  SensorRead();
  invcondition();
  condition();
  normal_line_PD();
}




//////////////////////////////////////////////Motor Code end/////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////Mbeak start///////////////////////////////////////////////////////////////////////
void Mbreak()
{
  motor(0, 0);
  delay(20);
  motor(-10 * lm, -10 * rm);
  delay(5);
  motor(0, 0);
}

