#include "Arduino.h"
#include "Ticker.h"
#include "MyTimer.h"
#include "MyKey.h"
#include "MyBlueT.h"
#include "MySerial.h"

Ticker MyTicker;

void MyTimer_CalBack()
{
    // 1ms 定时任务
    MyKey_Loop();
    MySerial_Loop();
    Bluetooth_Loop();
}

void MyTimer_Init()
{
    MyTicker.attach_ms(10,MyTimer_CalBack);
    Serial.println("定时器初始化完成\n");
}