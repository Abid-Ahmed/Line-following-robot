bool turnCondition(char c) {
  if (blackCondition()) {
    endPoint();
    return true;
  } else if (Tcondition() || plusCondition()) {
    //digitalWrite(R_LED, HIGH);
    lastSpeedL = baseSpeed;
    lastSpeedR = baseSpeed;
    botBreak(40);
    if (dir == 'L')
      path += 'L';
    else if (dir == 'R')
      path += 'R';

    turn(leftSign * turnSpeed, rightSign * turnSpeed);
    return true;
  }

  else if ((lastRead == 678 || lastRead == 78 || lastRead == 8) && c == 'L') {  //left 90
    if (dir == 'L')
      path += 'L';
    else
      path += 'R';  ////////////////////S

    turn(leftSign * turnSpeed, rightSign * turnSpeed);
    return true;
  }

  else if ((lastRead == 12300000 || lastRead == 12000000 || lastRead == 10000000) && c == 'R') {  //Right 90
    if (dir == 'R')
      path += 'R';
    else
      path += 'L';  /////////////////////S

    turn(leftSign * turnSpeed, rightSign * turnSpeed);
    return true;
  }

  //Read == 300000 || Read == 340000 || Read == 40000 || Read == 45000 || Read == 5000
  else if (Read) {
    if ((dir == 'R' && c == 'L') || (dir == 'L' && c == 'R')) {
      path += 'S';
      onLinePID();
    } else if (dir == 'L' && c == 'L') {
      path += 'L';
      turn(-turnSpeed, turnSpeed);
    } else if (dir == 'R' && c == 'R') {
      path += 'R';
      turn(turnSpeed, -turnSpeed);
    }
    return true;
  }

  else return false;
}



bool soluationTurn(char c) {
  if (blackCondition()) {
    digitalWrite(R_LED, 1);
    bool i = 1;
    botBreak(80);
    delay(10000);
    while (blackCondition()) {
      sensorRead();
      motor(0, 0);
      delay(500);
      digitalWrite(R_LED, i);
      i = !i;
    }

    digitalWrite(R_LED, 0);

    return true;
  } else if (Tcondition() || plusCondition()) {
    if (path[pathCount] == 'S') {
      onLinePID();
    } else if (path[pathCount] == 'R') {
      turn(turnSpeed, -turnSpeed);
    } else if (path[pathCount] == 'L') {
      turn(-turnSpeed, turnSpeed);
    }
    pathCount++;
    return true;
  }


  else if ((lastRead == 678 || lastRead == 78 || lastRead == 8) && c == 'L') {  //left 90
    if (c == 'L' && path[pathCount] == 'L')
      turn(-turnSpeed, turnSpeed);
    else
      turn(turnSpeed, -turnSpeed);
    pathCount++;
    return true;
  } else if ((lastRead == 12300000 || lastRead == 12000000 || lastRead == 10000000) && c == 'R') {  //Right 90
    if (c == 'R' && path[pathCount] == 'R')
      turn(turnSpeed, -turnSpeed);
    else
      turn(-turnSpeed, turnSpeed);
    pathCount++;
    return true;
  }

  else if (Read) {
    if (c == 'L' && path[pathCount] == 'L')
      turn(-turnSpeed, turnSpeed);
    else if (c == 'R' && path[pathCount] == 'R')
      turn(turnSpeed, -turnSpeed);
    else onLinePID();
    pathCount++;
    return true;
  }

  else return false;
}

void endPoint() {
  botBreak(60);
  digitalWrite(R_LED, 1);
  if (Turn > 0) {
    mazeSoluation();
    writeStringToEEPROM(50, path);
    Serial.println("Write: ");
    Serial.println(path);
  }
  Serial.println(Turn);
  path = readStringFromEEPROM(50);
  Serial.println(path);

  mazeSolve = true;
  scan = false;
  digitalWrite(R_LED, 0);
  bool i = 1;
  while (!digitalRead(buttonPin)) {
    delay(100);
    digitalWrite(R_LED, i);
    i = !i;
  }
  digitalWrite(R_LED, 0);
}

void white() {
  if (scan == true && mazeSolve == false) {
    path += 'B';
    motor(baseSpeed, baseSpeed);
    delay(L_Delay);
    turn(leftSign * turnSpeed, rightSign * turnSpeed);
  } else {
    botBreak(60);
    while (Read == 0) {
      motor(0, 0);
      sensorRead();
    }
  }
}

void starAction() {
  if (scan == true && mazeSolve == false) {
    if (dir == 'R')
      path += 'R';
    else
      path += 'L';
    motor(baseSpeed, baseSpeed);
    delay(130);
    turn(leftSign * turnSpeed, rightSign * turnSpeed);
  } else if (scan == false && mazeSolve == true) {
    if (path[pathCount] == 'R') {
      turn(turnSpeed, -turnSpeed);
    } else if (path[pathCount] == 'L') {
      turn(-turnSpeed, turnSpeed);
    } else if (path[pathCount] == 'S' && dir == 'L') {
      turn(turnSpeed, -turnSpeed);
    } else if (path[pathCount] == 'S' && dir == 'R') {
      turn(-turnSpeed, turnSpeed);
    } else onLinePID();
    pathCount++;
  }
}

void turnLeft() {
  bigRead = 0;
  for (int i = 0; i < nintyDegDelay; i++) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
  }
  if (mazeSolve == false && scan == true) {
    if (turnCondition('L') == false) {
      turn(-turnSpeed, turnSpeed);
      path += 'L';
    }
  } else if (mazeSolve == true && scan == false) {
    if (soluationTurn('L') == false) {
      turn(-turnSpeed, turnSpeed);
      pathCount++;
    }
  }
}

void turnRight() {
  bigRead = 0;
  for (int i = 0; i < nintyDegDelay; i++) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
  }
  if (mazeSolve == false && scan == true) {
    if (turnCondition('R') == false) {
      turn(turnSpeed, -turnSpeed);
      path += 'R';
    }
  } else if (mazeSolve == true && scan == false) {
    if (soluationTurn('R') == false) {
      turn(turnSpeed, -turnSpeed);
      pathCount++;
    }
  }
}
void turnRight45() {
  digitalWrite(R_LED, HIGH);
  angle45 = true;
  while (Read) {
    motor(baseSpeed, baseSpeed);
    sensorRead();
    if (lastRead / 10000000 || lastRead / 12000000 || lastRead / 12300000) {
      break;
    }
  }
  botBreak(100);
  //  if (lastRead / 10000000 || lastRead / 12000000 || lastRead / 12300000) {
  //
  //    sen[3] = 0;
  //    sen[4] = 0;
  //    while (!sen[3] && !sen[4]) {
  //      motor( -baseSpeed, baseSpeed);
  //      sensorRead();
  //    }
  //  }
  //  else {
  motor(baseSpeed, -baseSpeed);
  delay(100);

  sen[3] = 0;
  sen[4] = 0;
  while (!sen[3] && !sen[4]) {
    motor(baseSpeed, -baseSpeed);
    sensorRead();
  }
  digitalWrite(R_LED, 0);
}

void turnLeft45() {
  //  digitalWrite(R_LED, 1);
  angle45 = true;
  //  while (Read) {
  //    motor(baseSpeed, baseSpeed);
  //    sensorRead();
  //    if (lastRead % 10 == 8 || lastRead % 100 == 78 || lastRead % 1000 == 678)
  //      break;
  //  }
  botBreak(10);

  motor(-turnSpeed, turnSpeed);
  delay(240);

  sen[3] = 0;
  sen[4] = 0;
  while (!sen[3] && !sen[4]) {
    motor(-turnSpeed, turnSpeed);
    sensorRead();
  }
  //  digitalWrite(R_LED, 0);
}


void turn(int left, int right) {
  botBreak(Break);
  motor(left, right);
  delay(120);
  Turn++;
  if (left < right) {
    sen[2] = 0;
    sen[3] = 0;
    while (!sen[3] && !sen[2]) {
      motor(left, right);
      sensorRead();
    }
  } else {
    sen[4] = 0;
    sen[5] = 0;
    while (!sen[4] && !sen[5]) {
      motor(left, right);
      sensorRead();
    }
  }
  botBreak(40);
}

void delayTurn() {
  botBreak(40);
  motor(-baseSpeed, baseSpeed);
  delay(600);
  sen[3] = 0;
  sen[4] = 0;
  while (!sen[3] || !sen[4]) {
    motor(-baseSpeed, baseSpeed);
    sensorRead();
  }
  botBreak(60);
}
