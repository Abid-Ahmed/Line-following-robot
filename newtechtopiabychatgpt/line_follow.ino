void line_follow() {
    reading();

    // =======================================
    // SUM = 0 → dead zone / turning execution
    // =======================================
    if (sum == 0) {
        delay(10);
        if (turn != 's') {
            (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);
            while (!s[3] && !s[4]) reading();
            turn = 's';
        }
    }

    // =======================================
    // Normal line (sum 1 or 2)
    // =======================================
    else if (sum == 1 || sum == 2) {

        // Centered
        if (sensor == 0b00011000) {
            if (pos != 0) {
                (pos > 0) ? motor(-10 * lsp, 10 * rsp)
                          : motor(10 * lsp, -10 * rsp);

                delay(abs(pos) * 5);
            }
            pos = 0;   // recommended
            motor(10 * lsp, 10 * rsp);
        }

        // Right side corrections
        else if (sensor == 0b00001000) motor(10 * lsp, 9 * rsp);
        else if (sensor == 0b00001100) { if (pos <  1) pos = 1;  motor(10 * lsp, (9 - 1 * line_prop) * rsp); }
        else if (sensor == 0b00000100) { if (pos <  2) pos = 2;  motor(10 * lsp, (9 - 2 * line_prop) * rsp); }
        else if (sensor == 0b00000110) { if (pos <  3) pos = 3;  motor(10 * lsp, (9 - 3 * line_prop) * rsp); }
        else if (sensor == 0b00000010) { if (pos <  4) pos = 4;  motor(10 * lsp, (9 - 4 * line_prop) * rsp); }
        else if (sensor == 0b00000011) { if (pos <  5) pos = 5;  motor(10 * lsp, (9 - 5 * line_prop) * rsp); }
        else if (sensor == 0b00000001) { if (pos <  6) pos = 6;  motor(10 * lsp, (9 - 6 * line_prop) * rsp); }

        // Left side corrections
        else if (sensor == 0b00010000) motor(9 * lsp, 10 * rsp);
        else if (sensor == 0b00110000) { if (pos > -1) pos = -1; motor((9 - 1 * line_prop) * lsp, 10 * rsp); }
        else if (sensor == 0b00100000) { if (pos > -2) pos = -2; motor((9 - 2 * line_prop) * lsp, 10 * rsp); }
        else if (sensor == 0b01100000) { if (pos > -3) pos = -3; motor((9 - 3 * line_prop) * lsp, 10 * rsp); }
        else if (sensor == 0b01000000) { if (pos > -4) pos = -4; motor((9 - 4 * line_prop) * lsp, 10 * rsp); }
        else if (sensor == 0b11000000) { if (pos > -5) pos = -5; motor((9 - 5 * line_prop) * lsp, 10 * rsp); }
        else if (sensor == 0b10000000) { if (pos > -6) pos = -6; motor((9 - 6 * line_prop) * lsp, 10 * rsp); }

    }

    // =======================================
    // Turn prediction (sum 3 to 5)
    // =======================================
    else if (sum >= 3 && sum <= 5) {
        if ((s[3] + s[4]) && s[0] && !s[7])
            turn = 'r';
        else if ((s[3] + s[4]) && !s[0] && s[7])
            turn = 'l';
    }

    // =======================================
    // ALL BLACK (sum = 8)
    // =======================================
    else if (sum == 8) {
        delay(100);   // reduced for safety
        reading();

        if (sum == 8) {
            motor(0, 0);
            while (sum == 8) reading();
        }
        else if (sum == 0)
            turn = 'r';  // or 'l'
    }
}
