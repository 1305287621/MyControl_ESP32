#include <Arduino.h>
#include "HardwareSerial.h"
#include "MyKey.h"
#include "MyTimer.h"
#include "MySerial.h"
#include "MyBlueT.h"

extern MyData_t Mydata;

void setup()
{
  Serial.begin(115200);
  delay(10);
  BlueT_Init();
  MyKey_Init();
  MySerial_Init();
  MyTimer_Init();
}

void loop()
{
  delay(500); 
}
