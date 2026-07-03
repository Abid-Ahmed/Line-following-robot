void calibration()
{
  long front = millis();
  while ((millis() - front) < 400)
  {
    s[0] = analogRead(A0);
    s[1] = analogRead(A1);
    s[2] = analogRead(A2);
    s[3] = analogRead(A3);
    s[4] = analogRead(A4);
    s[5] = analogRead(A5);
    s[6] = analogRead(A6);
    s[7] = analogRead(A7);

    for (i = 0; i <= 7; i++)
    {
      if (s[i] > smin[i])
        smin[i] = s[i];
      if (s[i] < smax[i])
        smax[i] = s[i];
    }
    motor(100, 100);
  } // while end
  Mbreak();
  long back = millis();
  while ((millis() - back) < 500)
  {
    s[0] = analogRead(A0);
    s[1] = analogRead(A1);
    s[2] = analogRead(A2);
    s[3] = analogRead(A3);
    s[4] = analogRead(A4);
    s[5] = analogRead(A5);
    s[6] = analogRead(A6);
    s[7] = analogRead(A7);

    for (i = 0; i <= 7; i++)
    {
      if (s[i] > smin[i])
        smin[i] = s[i];
      if (s[i] < smax[i])
        smax[i] = s[i];
    }
    motor(-100, -100);
  } // while end
  Mbreak();
  motor(0, 0);
  delay(100);
  for (i=0;i<8;i++)
{
  ref[i]=(smin[i]+smax[i])/2;
}

}