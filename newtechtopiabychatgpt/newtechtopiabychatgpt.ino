// ----- pins -----
#define lmf 3
#define lmb 4
#define lms 11
#define rmf 5
#define rmb 6
#define rms 7

// ----- sensors & state -----
int s[8];
int sum = 0, avg = 0;

const int baseMask[8] = {1, 2, 4, 8, 16, 32, 64, 128};   // binary weights
const int positionVal[8] = {1, 2, 3, 4, 5, 6, 7, 8};    // positions for PID

int threshold = 512;
int sensor = 0;             // bitmask of sensor readings

// ----- motor & control params -----
int lsp = 25, rsp = 25, tsp = 150;
int lbase = 200, rbase = 200;
int lmotor = 0, rmotor = 0;

// ----- PID tuning -----
float line_prop = 2.0f;
float kp = 5.0f;      
float kd = 15.0f;     
float ki = 0.01f;     

float PID = 0.0f;
float error[10] = {0.0f};

int pos = 0;
char turn = 's';

// ---------------- clamp helper ----------------
inline int clampInt(int v, int a, int b) {
  return (v < a) ? a : (v > b) ? b : v;
}

// --------------- setup ---------------
void setup() {
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lms, OUTPUT);
  pinMode(rms, OUTPUT);

  Serial.begin(9600);

  // safe motor test (motor() not included here)
  // motor(10 * lsp, 10 * rsp);
  delay(200);
  // motor(0, 0);
}

void loop() {
  // Choose whichever follow mode you want:
  // PID_follow();
  // line_follow();
//   semi_pid();
}
