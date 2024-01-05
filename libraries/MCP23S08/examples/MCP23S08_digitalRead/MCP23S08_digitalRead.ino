//
//    FILE: MCP23S08_digitalRead.ino
//  AUTHOR: Rob Tillaart
//    DATE: 2021-12-30
// PURPOSE: test MCP23S08 library
//     URL: https://github.com/RobTillaart/MCP23S08


#include "MCP23S08.h"


MCP23S08 MCP(10);
int rv = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("MCP23S08_LIB_VERSION: ");
  Serial.println(MCP23S08_LIB_VERSION);
  Serial.println();
  delay(100);

  SPI.begin();
  rv = MCP.begin();
  Serial.println(rv);

  rv = MCP.pinMode8(0xFF);   //  CHECK
  Serial.println(rv);


  Serial.print("HWSPI: ");
  Serial.println(MCP.usesHWSPI());

  Serial.println("TEST read1(pin)");
  for (int pin = 0; pin < 8; pin++)
  {
    int val = MCP.read1(pin);
    Serial.print(val);
    Serial.print(' ');
    delay(100);
  }
  Serial.println();
}


void loop()
{
  delay(1000);
  Serial.println("TEST read1(pin)");
  for (int pin = 0; pin < 8; pin++)
  {
    int val = MCP.read1(pin);
    Serial.print(val);
    Serial.print(' ');
    delay(100);
  }
  Serial.println();

}


//  -- END OF FILE --
