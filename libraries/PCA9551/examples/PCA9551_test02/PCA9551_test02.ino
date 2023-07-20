//
//    FILE: PCA9551_test02.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2023-07-17
// PURPOSE: test PCA9551 library
//     URL: https://github.com/RobTillaart/PCA9551


#include "Arduino.h"
#include "Wire.h"
#include "PCA9551.h"


PCA9551 leds(0x62);


void setup()
{
  Serial.begin(115200);
  Serial.print("PCA9551_LIB_VERSION: ");
  Serial.println(PCA9551_LIB_VERSION);
  Serial.println();

  if (leds.begin() == false)
  {
    Serial.println("Could not connect.");
    while(1);
  }

}


void loop()
{
  //  random blink
  leds.digitalWrite(0, random(2));

  //  steady blink
  leds.digitalWrite(1, !leds.digitalRead(1));

  //  output 2 follows 3
  leds.digitalWrite(2, leds.digitalRead(3));
  leds.digitalWrite(3, random(2));
  delay(1000);
}


//  -- END OF FILE --