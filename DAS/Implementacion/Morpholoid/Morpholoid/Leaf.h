#ifndef LEAF_H
#define LEAF_H

#include "RoboticRoot.h"
#include <iostream>

typedef struct INSTRUCTION_SET{
	int id_motor;
	int value;
	int speed;
}instruction_set;

class Leaf : public RoboticRoot{
public:
	Leaf(int id,int val, int spd, std::string n);
	std::string getName();
	void setName(std::string n);
	void printName();
	int getVal(void);
	void setVal(int val);
	int getId(void);
	void setId(int id);
	int getSpeed(void);
	void setSpeed(int s);
	void getInstruction(std::vector<instruction_set> *instruction_list);

private:
	int value;
	int id_motor;
	int speed;
};

#endif