void normal_line_PD()
{
  SensorRead();
  Leftfound = false;
  Rightfound = false;

  if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) > 0)
  {
    looptime = millis() - tlast;
    line = (s1 * 1 + s2 * 2.5 + s3 * 3.5 + s4 * 4 + s5 * 5 + s6 * 5.5 + s7 * 6.5 + s8 * 8) / (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8);
    error = 4.5 - line;

    PD = (error * kp) + (((error - lasterror) * kd) / looptime);
    PID = PD;

    motor((lm * 10 - PID), (rm * 10 + PID));
    // if ((error <= 0.5) && (error >= (-0.5)))
    if (error == 0)
    {
      x++;
    }
    else
    {
      x = 0;
    }
    lasterror = error;
    tlast = millis();
  }
  if (x > 50)
  {
    lm = maxLR;
    rm = maxLR;
  }
  else
  {
    lm = LMSpeed;
    rm = RMSpeed;
  }
}

