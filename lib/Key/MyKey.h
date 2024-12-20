#ifndef MyKey_H
#define MyKey_H

typedef struct
{
   int button1;
   int button2;
   int button3;
   int button4; 
}SerialSendData_t;

typedef struct
{
	float joint1_aspeed;
	float joint2_aspeed;
	float joint3_aspeed;
	float joint4_aspeed;
	float joint5_aspeed;
	float joint6_aspeed;
}SerialReceiveData_t;

typedef struct
{
	float joint1_aspeed;
	float joint2_aspeed;
	float joint3_aspeed;
	float joint4_aspeed;
	float joint5_aspeed;
	float joint6_aspeed;
}BlueTSendData_t;


typedef struct
{
    SerialSendData_t SeriaSendlData;
    SerialReceiveData_t SeriaReceivelData;
    BlueTSendData_t BlueTSendData;

}MyData_t;

void MyKey_Init(void);
void MyKey_Loop();


#endif