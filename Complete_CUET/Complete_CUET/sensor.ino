////////////////Motor Driver///////////////////////////
void motor(int left, int right) {
  int a = 0, b = 0, c = 0, d = 0;
  lastSpeedL = left;
  lastSpeedR = right;

  if (left > 0) a = left;
  else b = left * -1;
  if (right > 0) c = right;
  else d = right * -1;
  analogWrite(inA, a);
  analogWrite(inB, b);
  analogWrite(inC, c);
  analogWrite(inD, d);
}
void botBreak(int a) {
  motor(-lastSpeedL, -lastSpeedR);
  delay(a);
  motor(0, 0);
}



/////////////////////Sensor Read///////////////////////////
void sensorRead() {
  int i, j;
  if (Read) lastRead = Read;
  if (Read > bigRead) bigRead = Read;
  onBlack = 0;
  Read = 0;
  position = 0;
  /*
    for(i=0; i<8; i++){
      Serial.print(i+1);
      Serial.print(" ");
      Serial.println(analogRead(senArrPin[i]));
    } Serial.println();Serial.println();
    return;
  */

  for (i = 0; i < 8; i++)
    sen[i] = ((ref[i]) > analogRead(senArrPin[i])) ? BlackSerface : !BlackSerface;

  for (i = 0; i < 8; i++) {
    onBlack += sen[i];
    Read = (Read * 10 + (sen[i] * (i + 1)));
    position += (sen[i] * (i + 1));
  }
  if (onBlack)
    position /= onBlack;
  else position = setPoint;
}

void autoCal() {
  {
    long start = millis();
    while (millis() < (start + 450)) {

      for (i = 0; i <= 7; i++) {
        sen[i] = analogRead(senArrPin[i]);

        if (sen[i] < smin[i])
          smin[i] = sen[i];
        if (sen[i] > smax[i])
          smax[i] = sen[i];
      }
      motor(140, 140);
    }

    long back = millis();
    botBreak(50);
    while (millis() < (back + 550)) {
      for (i = 0; i < 8; i++) {
        sen[i] = analogRead(senArrPin[i]);
        if (sen[i] < smin[i])
          smin[i] = sen[i];
        if (sen[i] > smax[i])
          smax[i] = sen[i];
      }

      motor(-140, -140);
    }
    // for (int i = 0; i <= 7; i++)
    //   ref[i] = ((smin[i] + smax[i]) / 2);

    for (int i = 0; i < 8; i++) {
      EEPROM.put(i * 2, ((smax[i] + smin[i]) / 2));
    }


    motor(0, 0);
    delay(100);
  }
}
