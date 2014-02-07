#ifndef GETTER_H
#define GETTER_H

#include "State.h"
#include "Robot.h"
#include <iostream>

class Getter : public State{
public:
	void handleState();
};

#endif