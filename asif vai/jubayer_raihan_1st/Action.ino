void ENDCondition() {
  TEST(70);

  if (!Read) {
    turn(-turnSpeed, turnSpeed);  // T condition
  }

  else if (Read && !(sen[0] || sen[7]))  // Plus Condition
  {
    if (PlusDir == 'L') {
      turn(-turnSpeed, turnSpeed);
    } else if (PlusDir == 'R') {
      turn(turnSpeed, -turnSpeed);
    } else onLinePID();
  }

  else if (blackCondition()) {
    endPoint();
  }
}

void endPoint() {
  bot_break(80);
  while (Read) {
    motor(0, 0);
    sensorRead();
  }
}

void turnLeft() {
  for (int i = 0; i < Delay; i++) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
  }
  sensorRead();
  if (Read) {  //Dir rule
    onLinePID();
  } else
    turn(-turnSpeed, turnSpeed);
}

void turnRight() {
  for (int i = 0; i < Delay; i++) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
  }

  sensorRead();
  if (Read) {  // dir rule
    onLinePID();
  } else
    turn(turnSpeed, -turnSpeed);
}

void turn(int left, int right) {
  bot_break(80);
  motor(left, right);
  delay(160);

  if (left < right) {
    sen[3] = 0;
    sen[2] = 0;

    while (!sen[3] && !sen[2]) {
      motor(left, right);
      sensorRead();
    }
  }

  else {
    sen[5] = 0;
    sen[4] = 0;

    while (!sen[5] && !sen[4]) {
      motor(left, right);
      sensorRead();
    }
  }
  bot_break(50);
}

void turnLeft45() {
  for (int i = 0; i < ADelay; i++) {
    motor(100, 100);
    sensorRead();
  }
  sensorRead();
  if (Read) onLinePID();
  else
    turn(-turnSpeed, turnSpeed);
}

void turnRight45() {
  for (int i = 0; i < ADelay; i++) {
    motor(100, 100);
    sensorRead();
  }
  sensorRead();
  if (Read) {
    onLinePID();
  } else
    turn(turnSpeed, -turnSpeed);
}


void starAction() {
  bot_break(80);
  sen[3] = 0;
  sen[4] = 0;
  while (!sen[3] && !sen[4]) {
    motor(turnSpeed, -turnSpeed);
    sensorRead();
  }
  bot_break(80);
}

void whiteAction() {
  for (int i = 0; i < GapDelay; i++) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
  }
  if (lastError < -1) {
    sen[3] = 0;
    sen[2] = 0;
    while (!sen[3] && !sen[2]) {
      motor(-turnSpeed, turnSpeed);
      sensorRead();
    }
  }
  else if (lastError > 1) {
    sen[5] = 0;
    sen[4] = 0;
    while (!sen[5] && !sen[4]) {
      motor(turnSpeed, -turnSpeed);
      sensorRead();
    }
  }
  else {
    TEST(50);
    if (Read)
      motor(Left, Right);
    else {
      turn(turnSpeed, -turnSpeed);
    }
  }
}