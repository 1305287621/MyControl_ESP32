#include <Arduino.h>
#include "MyKey.h"
MyData_t Mydata;

void MyKey_Init(void)
{
    pinMode(33, INPUT_PULLDOWN); //按键1设为上拉输入模式
    pinMode(32, INPUT_PULLDOWN); //按键2设为上拉输入模式
    pinMode(35, INPUT_PULLDOWN); //按键3设为上拉输入模式
    pinMode(34, INPUT_PULLDOWN); //按键4设为上拉输入模式
    Serial.println("按键初始化完成\n");
}

void MyKey_Loop()
{
    Mydata.SeriaSendlData.button1 = digitalRead(33);
    Mydata.SeriaSendlData.button2 = digitalRead(32);
    Mydata.SeriaSendlData.button3 = digitalRead(35);
    Mydata.SeriaSendlData.button4 = digitalRead(34);
}