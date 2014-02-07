#include "Instruction.h"

Instruction::Instruction(){
	baudRate = 57600;
}

Instruction::~Instruction(){

}

int Instruction::moveToPosition(std::vector<instruction_set> instruction_list){
	SerialPortF comPort;
	Dynamixel communication;
	hr = comPort.Open(L"COM1", baudRate);
	if(FAILED(hr))
	{
		printf("Cannot open COM1 port\n");
		return -1;
	}else{
		//printf("Starting communication\n");
	}

	communication.SendTossModeCommand(&comPort);
	for(int indx = 0;  indx < instruction_list.size(); indx++){
		communication.SetDynamixelPosition(&comPort, instruction_list[indx].id_motor, instruction_list[indx].value);	
	}
	
	comPort.Close();
	return 0;

}

int Instruction::moveWithSpeed(std::vector<instruction_set> instruction_list){
	SerialPortF comPort;
	Dynamixel communication;
	hr = comPort.Open(L"COM1", baudRate);
	if(FAILED(hr))
	{
		printf("Cannot open COM1 port\n");
		return -1;
	}else{
		//printf("Starting communication\n");
	}

	communication.SendTossModeCommand(&comPort);
	for(int indx = 0;  indx < instruction_list.size(); indx++){
		communication.SetDynamixelMovingSpeed(&comPort, instruction_list[indx].id_motor, instruction_list[indx].value, instruction_list[indx].speed);	
	}

	comPort.Close();
	return 0;
}