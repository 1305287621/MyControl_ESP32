#include <Arduino.h>
#include "MyKey.h"
MyData_t Mydata;

void MyKey_Init(void)
{
    pinMode(13, INPUT_PULLDOWN); //按键1设为上拉输入模式
    pinMode(12, INPUT_PULLDOWN); //按键2设为上拉输入模式
    pinMode(14, INPUT_PULLDOWN); //按键3设为上拉输入模式
    pinMode(27, INPUT_PULLDOWN); //按键4设为上拉输入模式
    Serial.println("按键初始化完成\n");
}

void MyKey_Loop()
{
    Mydata.SeriaSendlData.button1 = digitalRead(13);
    Mydata.SeriaSendlData.button2 = digitalRead(12);
    Mydata.SeriaSendlData.button3 = digitalRead(14);
    Mydata.SeriaSendlData.button4 = digitalRead(27);
}