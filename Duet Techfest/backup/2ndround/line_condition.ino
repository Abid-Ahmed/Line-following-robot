void condition()
{
  if ((s4 + s5) >= 1 && (s8 == 1) && (s7 == 0 || s6 == 0) && (s1 + s2) == 0) // right45
  {

    delay(5);
    SensorRead();
    if ((s4 + s5) >= 1 && (s8 == 1) && (s7 == 0 || s6 == 0) && (s1 + s2) == 0) // right45 confirm
    {

      t = millis();
      while (((millis() - t) < linedelay * 6) && ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) > 0))
      {
        SensorRead();
        motor(100, 100);
      }
      delay(10);
      SensorRead();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0)
      {
       
        turnright45();
        
      }
      else if (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 >= 1)
      {
        
        Ra45F();
        
      }
    }
  }
  //////////////////////////////////////////// left 45 degree found.///////////////////////////////////////////////////

  else if ((s4 + s5) >= 1 && (s1 == 1) && (s3 == 0 || s2 == 0) && (s7 + s8) == 0)
  {

    delay(5);
    SensorRead();
    if ((s4 + s5) >= 1 && (s1 == 1) && (s3 == 0 || s2 == 0) && (s7 + s8) == 0)
    {

      t = millis();
      while (((millis() - t) < linedelay * 6) && ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) > 0))
      {
        SensorRead();
        motor(100, 100);
      }
      delay(10);
      SensorRead();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0)
      {
        
        turnleft45();
        
      }
      else if (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 >= 1)
      {

        
        Le45F();
        
      }
    }
  }
  else if ((s2 + s3 >= 2) && (s1+s4+s5+s8==0) && (s6 + s7 >= 1)) // Y Found
  {
    motor(lastSpeedL, lastSpeedR);
    delay(5);
    SensorRead();
    if ((s2 + s3 >= 2) && (s1+s4+s5+s8==0) && (s6 + s7 >= 1))
    {
         
      t = millis();
      while (((millis() - t) < linedelay * 3) && ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) > 0))
      {
        SensorRead();
        motor(50, 50);
      }
      delay(10);
      SensorRead();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0)
      {
        
        Y_branch();
        
      
      }
      
    }
  }
  else if ((s1 + s2 + s3 + s4 + s5) >= 4) // left found
  {
    motor(lastSpeedL, lastSpeedR);
    delay(5);
    SensorRead();
    if ((s1 + s2 + s3 + s4 + s5) >= 4) // leftfound confirm
    {
      t = millis();
      while ((millis() - t < linedelay))
      {
        SensorRead();
        if ((s8 >= 1))
        {
          Rightfound = true;
        }
        else if ((s1 + s2) == 0)
        {
          break;
        }
        motor(cs, cs);
      }
      delay(15);
      SensorRead();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 >= 7) && (Rightfound == true)) // end found
      {
        
        end();
        
      }
      else if ((s1 == 0 && s2 == 0) && ((s3 + s4 + s5 + s6) >= 1) && (Rightfound == true)) // Plus found
      {
        
        Plus_Branch();
     
      }

      else if (((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0) && (Rightfound == true)) // T found
      {
       
        T_Branch();
       
      }
      //       else if ((s1 == 0 && s2 == 0) && ((s7+s8) >= 1) && (Rightfound == false))
      // {
      //   disp("Left Forward Right");
      //  turnright();
      //   disp("");
      // }
      else if ((s1 == 0 && s2 == 0) && ((s3 + s4 + s5 + s6) >= 1) && (Rightfound == false)) // Left forward found
      {

        
        LeF_Branch();
        
      }

      else if (((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0) && (Rightfound == false)) // Only left
      {

        
        turnleft();
       
      }
    }
  }

  ////////////////////////////////////Right Found////////////////////////////////////

  else if ((s4 + s5 + s6 + s7 + s8) >= 4) // right found
  {
    motor(lastSpeedL, lastSpeedR);
    delay(5);
    SensorRead();
    if ((s4 + s5 + s6 + s7 + s8) >= 4) // Rightfound confirm
    {
      t = millis();
      while ((millis() - t <= linedelay))
      {
        SensorRead();
        if ((s1 >= 1))
        {
          Leftfound = true;
        }
        else if ((s7 + s8) == 0)
        {
          break;
        }
        motor(cs, cs);
      }
      delay(15);
      SensorRead();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 >= 7) && (Leftfound == true)) // end found
      {
        
        end();
        
      }
      else if ((s7 == 0 && s8 == 0) && ((s3 + s4 + s5 + s6) >= 1) && (Leftfound == true)) // Plus found
      {
        
        Plus_Branch();
        
      }

      else if (((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0) && (Leftfound == true)) // T found
      {
       
        T_Branch();
        
      }
      // else if (s7 == 0 && s8 == 0 && ((s1+s2) >= 1) && (Leftfound == false)) // Right forward Left
      // {
      //   disp("Right F Left");
      //  turnright();
      //   disp("");
      // }

      else if (s7 == 0 && s8 == 0 && ((s3 + s4 + s5 + s6) >= 1) && (Leftfound == false)) // Right forward found
      {
       
        RaF_Branch();
        
      }
      else if (((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0) && (Leftfound == false)) // Only right
      {
        

        turnright();
        
      }
    }
  }
else if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0)
{
  motor(lastSpeedL, lastSpeedR);
  t = millis();
  while (((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) == 0) && ((millis() - t) < (linedelay)))
  {
    // if (D < 40 && D != 0)
    // {
    //motor(100, 100);
    //SensorRead();
    //D = lDist();
    // }
    // else
    {
      motor(lastSpeedL, lastSpeedR);
      SensorRead();
    }
  }
}
}
void invcondition()
{
  t = true;
  if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) >= 6 && (s3 == 0 || s4 == 0 || s5 == 0 || s6 == 0))
  {
    motor(lastSpeedL, lastSpeedR);
    delay(5);
    SensorRead();
    if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) >= 6 && (s3 == 0 || s4 == 0 || s5 == 0 || s6 == 0))
    {
      if (inv == false)
      {
        inv = true;
        lm = LMSpeed;
        rm = RMSpeed;
      }
      else if (inv == true)
      {
        inv = false;
        lm = LMSpeed;
        rm = RMSpeed;
      }
    }
  }
  else if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) >= 6 && (s3 == 0 || s4 == 0 || s5 == 0 || s6 == 0))
  {
    motor(lastSpeedL, lastSpeedR);
    delay(5);
    SensorRead();
    if ((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) >= 6 && (s3 == 0 || s4 == 0 || s5 == 0 || s6 == 0))
    {
      if (inv == false)
      {
        inv = true;
        lm = LMSpeed;
        rm = RMSpeed;
      }
      else if (inv == true)
      {
        inv = false;
        lm = LMSpeed;
        rm = RMSpeed;
      }
    }
  }
}
void turnleft()
{
  motor(delayspeed, delayspeed);
  delay(turndelay);
  // motor(0, 0);
  // delay(20);
  Mbreak();

  SensorRead();
  t = millis();
  while ((s4 + s5 >= 1))
  {
    motor(-123, 123);
    SensorRead();
  }
  while ((s2 == 0) && ((millis() - t) < 650))
  {
    motor(-150, 150);
    SensorRead();
  }
  Mbreak();
  motor(150, -150);
  delay(20);
  // motor(0, 0);
  // delay(10);
  Leftfound = false;
  Rightfound = false;
}
void turnright()
{

  motor(delayspeed,delayspeed);
  delay(turndelay);
  // motor(0, 0);
  // delay(20);
  // Mbreak();
  SensorRead();
  t = millis();
  while ((s4 + s5 >= 1))
  {
    motor(123, -123);
    SensorRead();
  }
  while ((s7 == 0) && ((millis() - t) < 750))
  {
    motor(150, -150);
    SensorRead();
  }
  Mbreak();
  // motor(-150, 150);
  // delay(20);
  // motor(0, 0);
  // delay(10);
  Leftfound = false;
  Rightfound = false;
}

void uturn()
{

  motor(180, 180);
  delay(uturndelay);
  motor(0, 0);
  delay(2);

  Mbreak();
  SensorRead();
  t = millis();

  while ((s8 == 0) && ((millis() - t) < 700))
  {
    motor(200, -200);
    SensorRead();
  }
  Mbreak();
  motor(-200, 200);
  delay(30);
  motor(0, 0);
  delay(10);
  Leftfound = false;
  Rightfound = false;
}

void turnleft45()
{
  motor(0, 0);
  delay(turndelay);
  // motor(-10 * lm, -10 * rm);
  // delay(3 * linedelay);
  SensorRead();
  t = millis();
  // Mbreak();
  while ((s1) >= 1)
  {
    motor(-120, 120);
    SensorRead();
  }
  while ((s3 == 0) && ((millis() - t) < (750)))
  {
    motor(-150, 150);
    SensorRead();
  }
  SensorRead();
  motor(120, -120);
  delay(30);
  motor(0, 0);
  delay(10);
}

void turnright45()
{
  motor(0, 0);
  delay(turndelay);
  SensorRead();
  t = millis();
  while ((s8 >= 1))
  {
    motor(120, -120);
    SensorRead();
  }
  while ((s6 == 0) && (millis() - t) < 750)
  {
    motor(150, -150);
    SensorRead();
  }
  motor(-120, 120);
  delay(30);
  motor(0, 0);
  delay(10);
}

void end()
{
  SensorRead();
  if (lap == false)
  {
    
  Mbreak();
  delay(8000);
  motor(100,100);
  delay(900);
    
    lap = true;
  }
  else if (lap == true)
  {
    SensorRead();
    while (s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 >= 8)
    {
      SensorRead();
      motor(0, 0);
    }
    lap = false;
  }
}
void O_Branch()
{
  
  turnright();
  SensorRead();
  while (s8 != 1)
  {
    normal_line_PD();
  }
  motor(200,200);
  delay(40);
  
  turnright();
  Mbreak();
  
}
void T_Branch()
{
  if(tcount==0){
    turnright();
    tcount++;
  }
  else if(tcount==1){
    O_Branch();
     tcount++;
    
  }
   else if(tcount==2){
    turnleft();
  }

}
void Plus_Branch()
{

// normal_line_PD();
 turnright();                                                           
  
}
void RaF_Branch()
{
 turnright();
// normal_line_PD();


}                                                                                  
void LeF_Branch()
{                     
 turnleft();
// normal_line_PD();

  
}
void Le45F()
{
normal_line_PD();
}
void Ra45F()
{
  turnright45();
}
void Y_branch()
{
turnright();
}
void Olympic()
{
  Mbreak();
  delay(3000);
}