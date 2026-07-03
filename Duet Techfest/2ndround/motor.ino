void motor(int left, int right)
{
  if (left > maxSpeed)
  {
    left = maxSpeed;
  }
  if (left < -maxSpeed)
  {
    left = -maxSpeed;
  }
  if (right > maxSpeed)
  {
    right = maxSpeed;
  }
  if (right < -maxSpeed)
  {
    right = -maxSpeed;
  }
  lastSpeedL = left;
  lastSpeedR = right;
  int a = 0, b = 0, c = 0, d = 0;
  if (left < 0)
  {
    a = left * -1;
  }
  else
    b = left;

  if (right < 0)
    c = right * -1;
  else
    d = right;

  analogWrite(M1, a);
  analogWrite(M2, b);
  analogWrite(M3, c);
  analogWrite(M4, d);
}