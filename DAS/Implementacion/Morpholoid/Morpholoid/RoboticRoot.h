#ifndef ROBOTICROOT_H
#define ROBOTICROOT_H

#include <string>
#include <vector>


class RoboticRoot{
public:
	std::string name;
	virtual void printName() = 0;
};

#endif