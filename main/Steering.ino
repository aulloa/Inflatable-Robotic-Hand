void steering()
  {
    if(Xbox.getAnalogHat(LeftHatX, i) > 7500 || Xbox.getAnalogHat(LeftHatX, i) < -7500 || Xbox.getAnalogHat(LeftHatY, i) > 7500 || Xbox.getAnalogHat(LeftHatY, i) < -7500 || Xbox.getAnalogHat(RightHatX, i) > 7500 || Xbox.getAnalogHat(RightHatX, i) < -7500 || Xbox.getAnalogHat(RightHatY, i) > 7500 || Xbox.getAnalogHat(RightHatY, i) < -7500) 
      { 
        if(Xbox.getAnalogHat(LeftHatX, i) > 7500)
          {
          if (Xbox.getAnalogHat(LeftHatX, i) > 26000)
            {
            turn_right();
            Rpwm = abs(Xbox.getAnalogHat(LeftHatX, i)-32768)/26.6;
            }
          }
      if (Xbox.getAnalogHat(LeftHatX, i) < -7500)
        {       
        if (Xbox.getAnalogHat(LeftHatX, i) < -26000)
          {
          Lpwm = (Xbox.getAnalogHat(LeftHatX, i)+32768)/26.6;
          turn_left();
          }
        }
    }
  }

void turn_left()
{
  analogWrite(LeftMotor,Lpwm);   // set left motor pwm slower
  strcpy(s,"L");//for print statment
}
 
void turn_right()
{
  analogWrite(RightMotor,Rpwm);   // set leg 1 of the H-bridge low
  strcpy(s,"R");//for print statments
}
