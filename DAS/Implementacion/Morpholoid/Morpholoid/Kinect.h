#ifndef KINECT_H
#define KINECT_H

#include "InTemplate.h"
#include "Gestures.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <NuiApi.h>

class Kinect : public InTemplate{
public:
	Kinect();
	Gestures *gesture;
	int connection;
	void ioOperation();
};



#endif