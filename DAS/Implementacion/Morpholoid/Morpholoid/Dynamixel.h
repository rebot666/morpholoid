#ifndef DYNAMIXEL_H
#define DYNAMIXEL_H


#include <Windows.h>
#include "SerialPort.h"
#include <iostream>

class Dynamixel
{
public:
	Dynamixel(void);
	~Dynamixel(void);
	bool CreateAX12SetPositionCommand(BYTE id, short goal, BYTE* pBuffer, DWORD* pSize);
	bool CreateAX12SetCommand(BYTE id, short goal, short speed , BYTE* pBuffer, DWORD* pSize);
	bool SetDynamixelPosition(SerialPortF *pSerialPort, unsigned int id, int position);
	bool SetDynamixelMovingSpeed(SerialPortF *pSerialPort, unsigned int id, int position, int speed);
	bool SendTossModeCommand(SerialPortF *pSerialPort);
};

#endif