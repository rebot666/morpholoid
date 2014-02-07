#ifndef COMPONENT_H
#define COMPONENT_H

#include "RoboticRoot.h"
#include <vector>
#include "Leaf.h"
#include <iostream>

class Component : public RoboticRoot{
private:
	std::vector<Leaf *> children;

public:
	Component(std::string n);
	void add(Leaf *element);
	std::string getName();
	void setName(std::string n);
	void printName();
	Leaf* searchLeaf(std::string name);
	bool stablishValueLeaf(std::string name, int v, int s);
	void getInstruction(std::vector<instruction_set> *instruction_list);

};

#endif
