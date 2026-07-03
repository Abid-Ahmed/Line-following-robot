void SensorRead()
{
  if (inv == false)
  {
    value1 = analogRead(A0);
    value2 = analogRead(A1);
    value3 = analogRead(A2);
    value4 = analogRead(A3);
    value5 = analogRead(A4);
    value6 = analogRead(A5);
    value7 = analogRead(A6);
    value8 = analogRead(A7);
    if (value1 < ref[0])
      s1 = 1;
    else
      s1 = 0;
    if (value2 < ref[1])
      s2 = 1;
    else
      s2 = 0;
    if (value3 < ref[2])
      s3 = 1;
    else
      s3 = 0;
    if (value4 < ref[3])
      s4 = 1;
    else
      s4 = 0;
    if (value5 < ref[4])
      s5 = 1;
    else
      s5 = 0;
    if (value6 < ref[5])
      s6 = 1;
    else
      s6 = 0;
    if (value7 < ref[6])
      s7 = 1;
    else
      s7 = 0;
    if (value8 < ref[7])
      s8 = 1;
    else
      s8 = 0;
  }
  else if (inv == true)
  {
    value1 = analogRead(A0);
    value2 = analogRead(A1);
    value3 = analogRead(A2);
    value4 = analogRead(A3);
    value5 = analogRead(A4);
    value6 = analogRead(A5);
    value7 = analogRead(A6);
    value8 = analogRead(A7);
    if (value1 < ref[0])
      s1 = 0;
    else
      s1 = 1;
    if (value2 < ref[1])
      s2 = 0;
    else
      s2 = 1;
    if (value3 < ref[2])
      s3 = 0;
    else
      s3 = 1;
    if (value4 < ref[3])
      s4 = 0;
    else
      s4 = 1;
    if (value5 < ref[4])
      s5 = 0;
    else
      s5 = 1;
    if (value6 < ref[5])
      s6 = 0;
    else
      s6 = 1;
    if (value7 < ref[6])
      s7 = 0;
    else
      s7 = 1;
    if (value8 < ref[7])
      s8 = 0;
    else
      s8 = 1;
  }
}