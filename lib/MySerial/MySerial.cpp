#include <Arduino.h>
#include "HardwareSerial.h"
#include "MyKey.h"
#include "MySerial.h"

HardwareSerial MySerial_stm32(1);
extern MyData_t Mydata;

// 发送结构体的函数
void sendStruct(const SerialSendData_t &data)
{
    MySerial_stm32.write((uint8_t *)&data, sizeof(data));
}
// 接收结构体的函数
bool receiveStruct(SerialReceiveData_t &data)
{
    static size_t index = 0;
    uint8_t *dataPtr = (uint8_t *)&data;

    while (MySerial_stm32.available())
    {
        dataPtr[index] = MySerial_stm32.read();
        index++;
        if (index >= sizeof(data))
        {
            index = 0;   // 重置索引，准备接收下一个结构体
            return true; // 接收完成
        }
    }
    return false; // 结构体未接收完整
}

void MySerial_Init()
{
    MySerial_stm32.begin(115200,SERIAL_8N1,26,25); // 串口初始化
    Serial.println("外部串口初始化完成");
}

void MySerial_Loop()
{
    //Serial.printf("输出:Button 1 is : %d Button 2 is : %d Button 3 is : %d Button 4 is : %d\n", Mydata.SeriaSendlData.button1,Mydata.SeriaSendlData.button2,Mydata.SeriaSendlData.button3,Mydata.SeriaSendlData.button4);
    //Serial.println("\n");
    sendStruct(Mydata.SeriaSendlData);
    receiveStruct(Mydata.SeriaReceivelData);
    //Serial.printf("stm32输入: %f  %f  %f  %f  %f  %f\n", Mydata.SeriaReceivelData.joint1_aspeed,Mydata.SeriaReceivelData.joint2_aspeed,Mydata.SeriaReceivelData.joint3_aspeed,Mydata.SeriaReceivelData.joint4_aspeed,Mydata.SeriaReceivelData.joint5_aspeed,Mydata.SeriaReceivelData.joint6_aspeed);
    memcpy(&Mydata.BlueTSendData,&Mydata.SeriaReceivelData,sizeof(Mydata.SeriaReceivelData));
    //Serial.printf("蓝牙输出: %f  %f  %f  %f  %f  %f\n", Mydata.BlueTSendData.joint1_aspeed,Mydata.BlueTSendData.joint2_aspeed,Mydata.BlueTSendData.joint3_aspeed,Mydata.BlueTSendData.joint4_aspeed,Mydata.BlueTSendData.joint5_aspeed,Mydata.BlueTSendData.joint6_aspeed);
    //Serial.println("\n");
}