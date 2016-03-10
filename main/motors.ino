  void motors()
    {
      for(uint8_t i=0;i<1;i++) 
        {
          strcpy(d,"n");// Set direction Print to nuetral//

          //** Motor Propulsion**//
          //If triggers are pressed set pulse to a duty cycle which increases
          //as a fucntion of the postion of the trigger with respect to normal.
          //pulse is then passed to a function in which it is set at the duty cycles for
          //the wheel motors
           
          if(Xbox.getButtonPress(L2, i))
            {
              //Serial.print("L2: ");
              //Serial.print(Xbox.getButtonPress(L2, i));
              pulse   = Xbox.getButtonPress(L2, i);
              forward = 0;
              clockwise(); 
            }
          
          if(Xbox.getButtonPress(R2, i))      
            {
              //Serial.print("R2: ");
              //Serial.println(Xbox.getButtonPress(R2, i));
              pulse = Xbox.getButtonPress(R2, i);
              forward = 1;
              counterClockwise(); 
            }
          //** Set pulse back to zero when triggger is not pressed**//
            if(!Xbox.getButtonPress(L2, i)&&!Xbox.getButtonPress(R2, i))
              {
              //Serial.print("L2: ");
              //Serial.print(Xbox.getButtonPress(L2, i));
              pulse = 0;
              forward = 0; 
              motors_stop(); 
              }

          //** Brake**//
          // Braking using the X button drives the motors in the oppositie direction they
          // were going. It determines that direction using the "forward" boolean 
          if(Xbox.getButtonClick(X, i))
            {
              Serial.println(F("Brake"));
              delay(600);
              brake_on = 1;
              pulse = 100;
             
            if (forward)
              clockwise();
            else
              counterClockwise();
            }   
        }
    }

//** Propulsion Functions**//
// The both functions set the wheels to a duty cycle determined by the triggers
// They also swing the dir pin high and low in order to control the direction of
//the motors    
void clockwise()
{
  //Serial.print("Rotation is clockwise and speed is ");
  //Serial.println(pulse);
  analogWrite(RightMotor,pulse);
  analogWrite(LeftMotor,pulse);
  digitalWrite(dir,LOW);
  strcpy(d,"f");// for print statements
}
 
void counterClockwise()
{
  //Serial.print("Rotation is counter-clockwise and speed is ");
  //Serial.println(pulse);
  analogWrite(RightMotor,pulse);
  analogWrite(LeftMotor,pulse);
  digitalWrite(dir,HIGH);
  strcpy(d,"b");//for print statments
}

void motors_stop()
{
  analogWrite(RightMotor,0);
  analogWrite(LeftMotor,0);
  pulse = 0;
}



