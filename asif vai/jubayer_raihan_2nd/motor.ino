void motor(int left, int right) {
  LSpeed = left;
  RSpeed = right;

  int a = 0, b = 0, c = 0, d = 0;
  (left < 0) ? b = abs(left) : a = left;
  (right < 0) ? c = abs(right) : d = right;

  analogWrite(A1, a);
  analogWrite(A2, b);
  analogWrite(B1, c);
  analogWrite(B2, d);
  
}
