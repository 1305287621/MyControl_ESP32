#include "Arduino.h"
#include "Ticker.h"
#include "MyTimer.h"
#include "MyKey.h"
#include "MyBlueT.h"
#include "MySerial.h"

Ticker MyTicker;
Ticker DataTicker;
extern MyData_t Mydata;

void MyTimer_CalBack()
{
    // 1ms 定时任务
    MyKey_Loop();
    MySerial_Loop();
    Bluetooth_Loop();
}
void DataTimer_CalBack()
{
    // 5s 定时任务
    Serial.printf("ESP32输出:Button 1 is : %d Button 2 is : %d Button 3 is : %d Button 4 is : %d\n", Mydata.SeriaSendlData.button1,Mydata.SeriaSendlData.button2,Mydata.SeriaSendlData.button3,Mydata.SeriaSendlData.button4);
    Serial.printf("stm32输入: %f  %f  %f  %f  %f  %f %f\n\n", Mydata.SeriaReceivelData.joint1_aspeed,Mydata.SeriaReceivelData.joint2_aspeed,Mydata.SeriaReceivelData.joint3_aspeed,Mydata.SeriaReceivelData.joint4_aspeed,Mydata.SeriaReceivelData.joint5_aspeed,Mydata.SeriaReceivelData.joint6_aspeed,Mydata.SeriaReceivelData.joint7_aspeed);
            
}

void MyTimer_Init()
{
    MyTicker.attach_ms(5,MyTimer_CalBack);
    DataTicker.attach(5,DataTimer_CalBack);
    Serial.println("定时器初始化完成\n");
}