#ifndef ROBOT_H
#define ROBOT_H

#include "Action.h"
#include "RoboticRoot.h"
#include "Component.h"
#include "Leaf.h"
#include "Component.h"
#include "Instruction.h"
#include <vector>
#include <string>

#define MOBILE 1
#define HUMANOID 2

class Robot{
public:
	Robot(int t);
	~Robot();
	int getType(void);
	void setType(int t);
	int getActionRobot();
	void setActionRobot(int a);
	bool defineRobot();
	void decodeAction();
	std::vector<instruction_set> getList();
	void addComponent(Component *c);
	void printHierarchy();
	std::string getName();
	void setName(std::string n);
	Component* searchComponent(std::string name);
	void getInstructions();
	bool executeInstructionSet();


private:
	Action *action;
	RoboticRoot *root;
	int type;
	std::vector<instruction_set> instructions;
	std::vector<Component *> children;
	std::string name;
	
};

#endif