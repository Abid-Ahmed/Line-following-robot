void motor(int a, int b){

    int pwmA = abs(a);
    int pwmB = abs(b);

    // direction control
    if(a >= 0){
        digitalWrite(lmf, HIGH);
        digitalWrite(lmb, LOW);
    } else {
        digitalWrite(lmf, LOW);
        digitalWrite(lmb, HIGH);
    }

    if(b >= 0){
        digitalWrite(rmf, HIGH);
        digitalWrite(rmb, LOW);
    } else {
        digitalWrite(rmf, LOW);
        digitalWrite(rmb, HIGH);
    }

    // PWM clamp
    if(pwmA > 255) pwmA = 255;
    if(pwmB > 255) pwmB = 255;

    analogWrite(lms, pwmA);
    analogWrite(rms, pwmB);
}
