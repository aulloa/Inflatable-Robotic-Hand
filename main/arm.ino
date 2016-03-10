void arm()
  {
    //** Define Steady State PWM (SSpwm) using left and right buttons **//
    //------------------------------------------------------------------//
    // the purpose of SSpwm is to allow some pressure in the arm in order 
    // maintain arm position. This relies on user feedback as he can change
    // the pwm duty cycle manually using the xbox RB and LB
    if(Xbox.getButtonPress(L1,i))
      {
        Serial.println(F("LB"));
        SSpwm = SSpwm-1;
        Serial.println(SSpwm);
      }
    if(Xbox.getButtonPress(R1,i))
      {
        Serial.println(F("RB"));
        SSpwm = SSpwm+1;
        Serial.println(SSpwm);
      }

    // ** Define Channel to Actuate **//
    
    //Defining which channel Adir will be inflated for deflate
    if(Xbox.getButtonPress(UP, i)) 
      {
      Adir = 1;
      Serial.println(F("Up"));
      }
    if(Xbox.getButtonPress(RIGHT, i)) 
      {
      Adir = 2;
      Serial.println(F("RIGHT"));
      }
    if(Xbox.getButtonPress(DOWN, i)) 
      {
      Adir = 3;
      Serial.println(F("DOWN"));
      }
    if(Xbox.getButtonPress(LEFT, i)) 
      {
      Adir = 4;
      Serial.println(F("LEFT"));
      }

    // ** Inflate**//
    // Inflation occurs by pressing the A button, which places Valve5 to allow pressure to 
    // reach the arm. Pressing A will also open the channel valve defined by the D-pad
    
    if(Xbox.getButtonPress(A, i))
      {
        digitalWrite(Valve5,HIGH);
        if(Adir == 1)
          {
          digitalWrite(Valve1,HIGH);
          Serial.println(F("Valve1"));
          }
        if(Adir == 2)
          {
          digitalWrite(Valve2,HIGH);
          Serial.println(F("Valve2"));
          }
        if(Adir == 3)
          {
          digitalWrite(Valve3,HIGH);
          Serial.println(F("Valve3"));
          }
        if(Adir == 4)
          {
          digitalWrite(Valve4,HIGH);
          Serial.println(F("Valve4"));
          }
        }

    // ** Deflate **//
    //Deflation occurs by pressing B which sets valve 5 to a positon which allows
    //channels to vent to atmosphere. It only opens the valve defined by the D-pad
    if(Xbox.getButtonPress(B, i))
      {
        digitalWrite(Valve5,LOW);
        if(Adir == 1)
          {
          digitalWrite(Valve1,HIGH);
          Serial.println(F("Valve1"));
          }
        if(Adir == 2)
          {
          digitalWrite(Valve2,HIGH);
          Serial.println(F("Valve2"));
          }
        if(Adir == 3)
          {
          digitalWrite(Valve3,HIGH);
          Serial.println(F("Valve3"));
          }
        if(Adir == 4)
          {
          digitalWrite(Valve4,HIGH);
          Serial.println(F("Valve4"));
          }
        }

      //** Set SSpwm**//
      // Sets all chanels not being inflated or deflated to SSpwm  
    if(!Xbox.getButtonPress(A,i)&&!Xbox.getButtonPress(B,i))
      {
      analogWrite(Valve1,SSpwm);
      analogWrite(Valve2,SSpwm);
      analogWrite(Valve3,SSpwm);
      analogWrite(Valve4,SSpwm);
      //Serial.println(F("SS"));
      }
  }
