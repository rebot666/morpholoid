#include "Action.h"

Action::Action(){
	setAction(-1);
}

Action::~Action(){

}


int Action::getAction(void){
	return action;
}

void Action::setAction(int a){
	action = a;
}

int Action::decodeGesture(int gesture){
	if(gesture == HANDS_UP){
		setAction(MOVEMENT_UP);
		return getAction();
	}
	if(gesture == HANDS_DOWN){
		setAction(MOVEMENT_DOWN);
		return getAction();
	}
	if(gesture == HORIZONTAL_HANDS){
		setAction(CENTER_SELF);
		return getAction();
	}
	if(gesture == VERTICAL_HANDS){
		setAction(-1);
		return getAction();
	}
	if(gesture == EQUAL_RIGHT_HANDS){
		setAction(-1);
		return getAction();
	}
	if(gesture == EQUAL_LEFT_HANDS){
		setAction(-1);
		return getAction();
	}
	if(gesture == CROSS_HANDS){
		setAction(-1);
		return getAction();
	}
	if(gesture == DOWN_L_RIGHT_HANDS){
		setAction(MOVEMENT_LEFT);
		return getAction();
	}
	if(gesture == DOWN_L_LEFT_HANDS){
		setAction(MOVEMENT_RIGHT);
		return getAction();
	}

	setAction(-1);
	return getAction();
	
	
}

std::string Action::getActionName(){
	switch(getAction()){
		case CENTER_SELF:
			return "CENTER SELF";
		default:
			return "No action defined";
	}
}