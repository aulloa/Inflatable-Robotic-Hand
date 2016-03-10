#include <XBOXRECV.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include "definitions.h"

// intiate library
USB Usb;
XBOXRECV Xbox(&Usb);

void setup() {
  TCCR1B = TCCR1B & 0b11111000 | 0x02;
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while(1); //halt
    motors_stop();
  }
  pins();
}
 
void loop() {
  Usb.Task();
  if(Xbox.XboxReceiverConnected) 
    {
    for(uint8_t i=0;i<1;i++) 
      {
        strcpy(s,"n");
        motors();
        arm();
        steering();

        // Prints
        Serial.print("Propulsion:");
        Serial.print(d);
        Serial.print("\t");
        Serial.print("Steering:");
        Serial.println(s);
//        static char line1[26];
//        sprintf(line1, "Propulsion: %s", d);
//        Serial.println(line1);
      }  
    }
  delay(1);
  } 
