#include "Dynamixel.h"


Dynamixel::Dynamixel(){
}

Dynamixel::~Dynamixel(){
}

bool Dynamixel::CreateAX12SetPositionCommand(BYTE id, short goal, BYTE* pBuffer, DWORD* pSize)
{   
	const unsigned int packetSize = 9;

	if(*pSize < packetSize)
	{
		return false;
	}

	// PACKET STRUCTURE: OXFF 0XFF ID LENGTH INSTRUCTION PARAMETER_1 EARAMETER_N CHECKSUM
	*pSize = packetSize;
	pBuffer[0] = 0xFF;
	pBuffer[1] = 0xFF;
	pBuffer[2] = id;
	pBuffer[3] = 2 /* number of parameters */ + 3;	// packet body length
	pBuffer[4] = 3;						// instruction id = write data
	// Parameters
	pBuffer[5] = 30;					// start address of position goal setting
	pBuffer[6] = BYTE(goal);			// goal low byte (to address 30)
	pBuffer[7] = BYTE(goal>>8);			// goal high byte (to address 31)
	
	// Checksum
	DWORD packetSum = 0;
	for(size_t i=2; i<=7; i++)
	{
		packetSum += pBuffer[i];
		
	}/*
	for(size_t i=0; i<=7; i++)
	{
		packetSum += pBuffer[i];
		printf("%X", pBuffer[i]);
	}
	std::cout << std::endl;*/
	
	pBuffer[8] = (BYTE)(~packetSum);
	//printf("%X %X %X %X %X %X %X %X %X\n", pBuffer[0], pBuffer[1], pBuffer[2], pBuffer[3], pBuffer[4], pBuffer[5], pBuffer[6] , pBuffer[7], pBuffer[8]);
	
	return true;
}

bool Dynamixel::CreateAX12SetCommand(BYTE id, short goal, short speed, BYTE* pBuffer, DWORD* pSize)
{   
	const unsigned int packetSize = 11;

	if(*pSize < packetSize)
	{
		return false;
	}

	// PACKET STRUCTURE: OXFF 0XFF ID LENGTH INSTRUCTION PARAMETER_1 EARAMETER_N CHECKSUM
	*pSize = packetSize;
	pBuffer[0] = 0xFF;
	pBuffer[1] = 0xFF;
	pBuffer[2] = id;
	pBuffer[3] = 2 /* number of parameters */ + 5;	// packet body length
	pBuffer[4] = 3;						// instruction id = write data
	// Parameters
	pBuffer[5] = 30;					// start address of position goal setting
	pBuffer[6] = BYTE(goal);			// goal low byte (to address 30)
	pBuffer[7] = BYTE(goal>>8);			// goal high byte (to address 31)
	pBuffer[8] = BYTE(speed);
	pBuffer[9] = BYTE(speed>>8);
	
	// Checksum
	DWORD packetSum = 0;
	for(size_t i=2; i<=9; i++)
	{
		packetSum += pBuffer[i];
		
	}
	
	pBuffer[10] = (BYTE)(~packetSum);
	//printf("%X %X %X %X %X %X %X %X %X\n", pBuffer[0], pBuffer[1], pBuffer[2], pBuffer[3], pBuffer[4], pBuffer[5], pBuffer[6] , pBuffer[7], pBuffer[8]);
	return true;
}

bool Dynamixel::SetDynamixelPosition(SerialPortF *pSerialPort, unsigned int id, int position)
{
	BYTE buffer[256];
	DWORD size = sizeof(buffer);

	if( !CreateAX12SetPositionCommand(id, (short)position, buffer, &size) )
	{
		return false;
	}

	HRESULT hr = pSerialPort->SendData(buffer, &size);
	if(FAILED(hr))
	{
		printf("Failed to send set dynamixel position command\n");
		return false;
	}
	Sleep(10);

	memset(buffer, 0, sizeof(buffer));
	size = sizeof(buffer);
	pSerialPort->ReceiveData(buffer, &size);

	if (size>4 && buffer[4] == 0)
	{
		printf("id=%d set to position=%d\n", id, position);
	}
	else
	{
		//printf("Error while setting id=%d position=%d, error:%d\n", id, position, buffer[4]);
		return false;
	}     
	
	return true;
}

bool Dynamixel::SetDynamixelMovingSpeed(SerialPortF *pSerialPort, unsigned int id, int position, int speed)
{
	BYTE buffer[256];
	DWORD size = sizeof(buffer);

	if( !CreateAX12SetCommand(id, (short)position, (short)speed ,buffer, &size) )
	{
		return false;
	}

	HRESULT hr = pSerialPort->SendData(buffer, &size);
	if(FAILED(hr))
	{
		printf("Failed to send set dynamixel position command\n");
		return false;
	}
	Sleep(10);

	memset(buffer, 0, sizeof(buffer));
	size = sizeof(buffer);
	pSerialPort->ReceiveData(buffer, &size);

	if (size>4 && buffer[4] == 0)
	{
		printf("id=%d set to position=%d and speed=%d\n", id, position, speed);
	}
	else
	{
		//printf("Error while setting id=%d position=%d, error:%d\n", id, position, buffer[4]);
		return false;
	}     
	
	return true;
}
bool Dynamixel::SendTossModeCommand(SerialPortF *pSerialPort)
{
	BYTE buffer[1024];
	buffer[0]='t';
	buffer[1]='\r';
	DWORD size = 2;

	HRESULT hr = pSerialPort->SendData(buffer, &size);
	if(FAILED(hr))
	{
		printf("Failed to send TOSS model command\n");
		return false;
	}
	Sleep(100);

	size = sizeof(buffer);
	pSerialPort->ReceiveData(buffer, &size);

	return true;
}
