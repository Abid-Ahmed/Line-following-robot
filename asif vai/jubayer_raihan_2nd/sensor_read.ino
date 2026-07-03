void sensorRead() {
  int i;
  onBlack = 0;
  Read = 0;
  position = 0;

  for (i = 0; i < 8; i++)
    sen[i] = ((ref[i]) < analogRead(ArrPin[i])) ? BlackSerface : !BlackSerface;

  for (i = 0; i < 8; i++) {
    onBlack += sen[i];
    Read = (Read * 10 + (sen[i] * (i + 1)));
    position += (sen[i] * (i + 1));
    // Serial.println(Read);
  }
  
  if (onBlack)
    position /= onBlack;
  else 
    position = setPoint;
}

void reCheck(int Delay) {
  motor(LSpeed, RSpeed);
  delay(Delay);
  sensorRead();
}

void bot_break(int a) {
  motor(-LSpeed, -RSpeed);
  delay(a);
  motor(0, 0);
}

void autoCal() {
  long start = millis();
  while (millis() < (start + 450)) {
    for (int i = 0; i <= 7; i++) {
      sen[i] = analogRead(ArrPin[i]);
      if (sen[i] < smin[i])
        smin[i] = sen[i];
      if (sen[i] > smax[i])
        smax[i] = sen[i];
    }
    motor(80, 80);
  }

  long back = millis();
  bot_break(50);

  while (millis() < (back + 550)) {
    for (int i = 0; i < 8; i++) {
      sen[i] = analogRead(ArrPin[i]);
      if (sen[i] < smin[i])
        smin[i] = sen[i];
      if (sen[i] > smax[i])
        smax[i] = sen[i];
    }
    motor(-80, -80);
  }

  for (int i = 0; i < 8; i++) {
    EEPROM.put(i * 2, ((smax[i] + smin[i]) / 2));
  }

  motor(0, 0);
  delay(100);
}

// Motor control function (assuming it exists but wasn't in the original code)
