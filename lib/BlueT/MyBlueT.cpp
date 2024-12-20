#include <Arduino.h>
#include "BluetoothSerial.h"
#include "MyKey.h"


BluetoothSerial SerialBT;
#define Master 0    //主从机模式选择 1主机 0从机
uint8_t address[6]={0x30,0x83,0x98,0xC3,0x50,0xDA}; //从机MAC地址 不同的蓝牙地址不同 需要自己修改
extern MyData_t Mydata;




void BlueT_Init()
{
    if(Master)
    {
        SerialBT.begin("ESP32 Master"); //Bluetooth device name
        Serial.println("The Bluetooth device has been started");
        SerialBT.connect(address);
    }
    else
    {
        SerialBT.begin("ESP32_SLAVE");       //开启蓝牙 名称为:"ESP32_SLAVE" 从机
        Serial.printf("\n蓝牙从机初始化完成\r\n");
    }
}


void Bluetooth_Loop()
{
    if (SerialBT.hasClient()) {
    // 发送结构体数据
    size_t bytesSent = SerialBT.write((uint8_t *)&Mydata.SeriaSendlData, sizeof(Mydata.SeriaSendlData));
    // 检查数据是否已全部发送
    if (bytesSent == sizeof(Mydata.SeriaSendlData)) {
      Serial.println("数据发送完成");
    } else {
      Serial.println("数据发送失败");
    }
    }
}

