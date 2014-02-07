#include "Robotis.h"

Robotis::Robotis(int t){
	type = t;
}

void Robotis::ioOperation(){
	Instruction *instruction = new Instruction();
	int res = -1;
	if(type == MOBILE){
		res = instruction->moveWithSpeed(instructions);
	}else if(type == HUMANOID){
		res = instruction->moveToPosition(instructions);
	}

}