void PID_follow(){
    PID_reading();
    for (int i = 9; i>=1; i--){
        error[i] = error[i-1];
    }
    error[0] = 4.5 - avg;

    // error = 4.5 - avg;   //4.5 = set position   this line is for two error omly
    float err_sum = 0;
    for (byte i= 0; i<10; i++){
        err_sum += error[i];
    }

    PID = error * kp + (error[1] - error[0])*kd + err_sum*ki;  // ki gradually increase or decrease so for making it zero quickly some time have ot divide by 2

    // PID = error * kp + (error-last_error)*kd + ((last_error+error)/2)*ki;  // ki gradually increase or decrease so for making it zero quickly some time have ot divide by 2
    // last_error = error;
    error[1] = error[0];

    rmotor = rbase - PID;
    lmotor = lbase + PID;

    motor(lmotor, rmotor);
}