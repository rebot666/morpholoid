#ifndef ROBOTIS_H
#define ROBOTIS_H

#include "OutTemplate.h"
#include "Robot.h"
#include "Instruction.h"

class Robotis : public OutTemplate{
public:
	Robotis(int t);
	void ioOperation();

private:
	std::vector<instruction_set> instructions;
	int type;
};

#endif