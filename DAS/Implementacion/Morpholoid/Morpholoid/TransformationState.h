#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "State.h"
#include "Robot.h"
#include <iostream>

class Transformation : public State{
public:
	void handleState();
};

#endif