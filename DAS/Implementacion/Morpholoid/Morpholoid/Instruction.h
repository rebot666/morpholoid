#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Dynamixel.h"
#include "SerialPort.h"
#include "Leaf.h"
#include <vector>

class Instruction{
public:
	Instruction();
	~Instruction();
	int moveToPosition(std::vector<instruction_set> instruction_list);
	int moveWithSpeed(std::vector<instruction_set> instruction_list);
private:
	DWORD baudRate;
	HRESULT hr;
};

#endif