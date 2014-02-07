#include "Leaf.h"

Leaf::Leaf(int id, int val, int spd,std::string n){
	setId(id);
	setVal(val);
	setName(n);
	setSpeed(spd);
	
}
std::string Leaf::getName(){
	return name;
}
void Leaf::setName(std::string n){
	name = n;
}
void Leaf::printName(){
	std::cout << "\t\t" << name << "   Id:" << id_motor << "    Valude:" << value <<std::endl;
}
int Leaf::getVal(void){
	return value;
}
void Leaf::setVal(int val){
	value = val;
}
int Leaf::getId(void){
	return id_motor;
}
void Leaf::setId(int id){
	id_motor = id;
}

int Leaf::getSpeed(void){
	return speed;
}
void Leaf::setSpeed(int s){
	speed = s;
}
void Leaf::getInstruction(std::vector<instruction_set> *instruction_list){
	instruction_set instruction;
	instruction.id_motor = getId();
	instruction.value = getVal();
	instruction.speed = getSpeed();
	instruction_list->push_back(instruction);
}