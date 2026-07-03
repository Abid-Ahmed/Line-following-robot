void semi_pid() {
    reading();

    // ======================
    // SUM == 0 → deadzone / turning area
    // ======================
    if (sum == 0) {
        delay(10);  // if bot is slow
        if (turn != 's') {
            (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);
            while (!s[3] && !s[4]) reading();
            turn = 's';
        }
    }

    // ======================
    // Normal line PID
    // ======================
    PID_reading();

    error[0] = 4.5 - avg;  // current error

    // PID CALCULATION (fixed array error)
    PID = error[0] * kp + (error[0] - error[1]) * kd;

    // Shift errors for next loop
    error[1] = error[0];

    rmotor = rbase - PID;
    lmotor = lbase + PID;

    motor(lmotor, rmotor);

    // ======================
    // TURN DETECTION
    // ======================
    if (s[0] && !s[7]) turn = 'r';  
    else if (!s[0] && s[7]) turn = 'l';

    // ======================
    // ALL BLACK (sum = 8)
    // ======================
    else if (sum == 8) {
        delay(200);
        reading();

        if (sum == 8) {
            motor(0, 0);
            while (sum == 8) reading();
        }
        else if (sum == 0) turn = 'r';  // or 'l'
    }
}
