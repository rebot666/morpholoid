#ifndef ACTION_H
#define ACTION_H

/*
	CENTER SELF: CENTER INTO ITSELF
		For Humanoid:
			Parallel Arms
		For Mobile:
			Make a Circle
*/
#include "Gestures.h"
#include <string>
#define CENTER_SELF 0 
#define MOVEMENT_UP 1
#define MOVEMENT_DOWN 2
#define MOVEMENT_LEFT 3
#define MOVEMENT_RIGHT 4


class Action{
private:
	int action;
public:
	Action();
	~Action();
	int getAction(void);
	void setAction(int a);
	int decodeGesture(int gesture);
	std::string getActionName();
};

#endif // !ACTION_H
