#include "Robot.h"



Robot::Robot(int t){
	setType(t);
	action = new Action();
	defineRobot();
	
}
Robot::~Robot(){
}

int Robot::getType(void){
	return type;
}
void Robot::setType(int t){
	type = t;
}

int Robot::getActionRobot(){
	return action->getAction();
}
void Robot::setActionRobot(int a){
	action->setAction(a);
}
bool Robot::defineRobot(){
	if(getType() == MOBILE){
		name = "Mobile Robot";
		Leaf *motor1 = new Leaf(0,0, 0,"motor0");
		Leaf *motor2 = new Leaf(1,0, 0,"motor1");
		Leaf *motor3 = new Leaf(2,0, 0,"motor2");
		Leaf *sensor1 = new Leaf(100,0, 0,"sensor1");
		Component *skeleton = new Component("Chasis");
		skeleton->add(motor1);
		skeleton->add(motor2);
		skeleton->add(motor3);
		skeleton->add(sensor1);
		addComponent(skeleton);
		printHierarchy();
		return true;
	}else if(getType() == HUMANOID){
		name = "Humanoid Robot";
		Leaf *motor1 = new Leaf(1,200, 0,"motor1");
		Leaf *motor2 = new Leaf(2,800, 0,"motor2");
		Leaf *motor3 = new Leaf(3,512, 0,"motor3");
		Leaf *motor4 = new Leaf(4,512, 0,"motor4");
		Leaf *motor5 = new Leaf(5,512, 0,"motor5");
		Leaf *motor6 = new Leaf(6,512, 0,"motor6");
		Leaf *motor7 = new Leaf(7,512, 0,"motor7");
		Leaf *motor8 = new Leaf(8,512, 0,"motor8");
		Leaf *motor9 = new Leaf(9,512, 0,"motor9");
		Leaf *motor10 = new Leaf(10,512, 0,"moto10");
		Leaf *motor11 = new Leaf(11,512, 0,"motor11");
		Leaf *motor12 = new Leaf(12,512, 0,"motor12");
		Leaf *motor13 = new Leaf(13,512, 0,"motor13");
		Leaf *motor14 = new Leaf(14,512, 0,"motor14");
		Leaf *motor15 = new Leaf(15,512, 0,"motor15");
		Leaf *motor16 = new Leaf(16,512, 0,"motor16");
		Leaf *motor17 = new Leaf(17,512, 0,"motor17");
		Leaf *motor18 = new Leaf(18,512, 0,"motor18");
		Leaf *sensor100 = new Leaf(100,512, 0,"sensor1");

		Component *chest = new Component("Arm");
		Component *right_arm = new Component("Right Arm");
		Component *left_arm = new Component("Left Arm");
		Component *torax = new Component("Torax");
		Component *right_leg = new Component("Right Leg");
		Component *left_leg = new Component("Left Leg");
		Component *head = new Component("Head");

		head->add(sensor100);
		chest->add(motor1);
		chest->add(motor2);
		right_arm->add(motor3);
		right_arm->add(motor5);
		left_arm->add(motor4);
		left_arm->add(motor6);
		torax->add(motor7);
		torax->add(motor8);
		right_leg->add(motor9);
		right_leg->add(motor11);
		right_leg->add(motor13);
		right_leg->add(motor15);
		right_leg->add(motor17);
		left_leg->add(motor10);
		left_leg->add(motor12);
		left_leg->add(motor14);
		left_leg->add(motor16);
		left_leg->add(motor18);

		addComponent(head);
		addComponent(chest);
		addComponent(right_arm);
		addComponent(left_arm);
		addComponent(torax);
		addComponent(right_leg);
		addComponent(left_leg);
		printHierarchy();
		return true;
	}
	return false;
}

void Robot::decodeAction(){
	/*
	switch(action->getAction()){
		case CENTER_SELF:
		
			std::cout << std::endl << "Action: " <<action->getActionName() << std::endl;
			switch (getType())
			{
				case MOBILE:
					Component *chasis;
					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 0);
						chasis->stablishValueLeaf("motor1", 0, 0);
						chasis->stablishValueLeaf("motor2", 0, 0);
						printHierarchy();
					}
					break;
				case HUMANOID:
					Component *right_arm;
					Component *left_arm;
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 512, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 512, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					printHierarchy();
					break;
			}

			break;
	}
	*/
	switch(getType()){
		case MOBILE:
			Component *chasis;
			switch (action->getAction())
			{
				case CENTER_SELF:
					
					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 0);
						chasis->stablishValueLeaf("motor1", 0, 0);
						chasis->stablishValueLeaf("motor2", 0, 0);
						//printHierarchy();
					}
					break;
				case MOVEMENT_UP:

					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 512);
						chasis->stablishValueLeaf("motor1", 0, 1535);
						chasis->stablishValueLeaf("motor2", 0, 512);
						//printHierarchy();
					}
					break;
				case MOVEMENT_DOWN:
					
					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 1535);
						chasis->stablishValueLeaf("motor1", 0, 512);
						chasis->stablishValueLeaf("motor2", 0, 1535);
						//printHierarchy();
					}
					break;
				case MOVEMENT_LEFT:
					
					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 1022);
						chasis->stablishValueLeaf("motor1", 0, 2046);
						chasis->stablishValueLeaf("motor2", 0, 0);
						//printHierarchy();
					}
					break;
				case MOVEMENT_RIGHT:
					
					chasis = searchComponent("Chasis");
					if(chasis != NULL){
						chasis->stablishValueLeaf("motor0", 0, 1022);
						chasis->stablishValueLeaf("motor1", 0, 0);
						chasis->stablishValueLeaf("motor2", 0, 1022);
						//printHierarchy();
					}
					break;
			}
			break;
		case HUMANOID:
			Component *right_arm;
			Component *left_arm;
			switch (action->getAction())
			{
				case CENTER_SELF:
					
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 512, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 512, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					//printHierarchy();
					break;
				case MOVEMENT_UP:
					
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 650, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 370, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					//printHierarchy();
					break;
				case MOVEMENT_DOWN:
					
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 370, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 650, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					//printHierarchy();
					break;
				case MOVEMENT_LEFT:
					
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 512, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 650, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					//printHierarchy();
					break;
				case MOVEMENT_RIGHT:
					
					right_arm = searchComponent("Right Arm");
					left_arm = searchComponent("Left Arm");
					if(right_arm != NULL && left_arm != NULL){
						right_arm->stablishValueLeaf("motor3", 370, 0);	
						right_arm->stablishValueLeaf("motor5", 512, 0);
						left_arm->stablishValueLeaf("motor4", 512, 0);
						left_arm->stablishValueLeaf("motor6", 512, 0);
					}
					//printHierarchy();
					break;
			}
			break;
	}
}

void Robot::addComponent(Component *c){
	children.push_back(c);
}

void Robot::printHierarchy(){
	std::cout << name << std::endl;
	for(int indx = 0; indx < children.size(); indx++){
		children[indx]->printName();
	}
}

std::string Robot::getName(){
	return name;
}
void Robot::setName(std::string n){
	name = n;
}


Component* Robot::searchComponent(std::string name){
	for(int indx = 0; indx < children.size(); indx++){
		if(children[indx]->name.compare(name) == 0){
			return children[indx];
		}
	}
	return NULL;
}

void Robot::getInstructions(){
	instructions.clear();
	for(int indx = 0; indx < children.size(); indx++){
		children[indx]->getInstruction(&instructions);
	}

	std::cout << std::endl << "Instructions:" << std::endl;
	for(int i = 0; i < instructions.size(); i++){
		std::cout << i <<") Motor:" <<instructions[i].id_motor << "  " << instructions[i].value << "  " << instructions[i].speed << std::endl;
	}
}

bool Robot::executeInstructionSet(){
	if(instructions.data() != NULL){
		Instruction *instruction = new Instruction();
		int res = -1;

		if(type == MOBILE){
			res = instruction->moveWithSpeed(instructions);
		}else if(type == HUMANOID){
			res = instruction->moveToPosition(instructions);
		}

		if(res == -1){
			return false;
		}else{
			return true;
		}
	}else{
		return false;
	}
	
}
