#ifndef SELECTION_H
#define SELECTION_H


#include "State.h"
#include "Robot.h"
#include <iostream>

class Selection : public State{
public:
	void handleState();
};

#endif