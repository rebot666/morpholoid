#include "Component.h"

Component::Component(std::string n){
	setName(n);
}

void Component::add(Leaf *element){
	children.push_back(element);
}

void Component::printName(){
	std::cout << "\t" << name << std::endl;
	for(int index = 0; index < children.size(); index++){
		children[index]->printName();
	}
}

std::string Component::getName(){
	return name;
}
void Component::setName(std::string n){
	name = n;
}

Leaf* Component::searchLeaf(std::string name){
	for(int indx = 0; indx < children.size(); indx++){
		if(children[indx]->name.compare(name) == 0){
			return children[indx];
		}
	}
	return NULL;
}

bool Component::stablishValueLeaf(std::string name, int v, int s){
	for(int indx = 0; indx < children.size(); indx++){
		if(children[indx]->name.compare(name) == 0){
			Leaf *temp = children[indx];
			temp->setVal(v);
			temp->setSpeed(s);
			return true;
		}
	}
	return false;
}

void Component::getInstruction(std::vector<instruction_set> *instruction_list){
	for(int index = 0; index < children.size(); index++){
		children[index]->getInstruction(instruction_list);
	}
}