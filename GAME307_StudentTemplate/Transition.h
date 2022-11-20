#ifndef TRANSITION_H
#define TRANSITION_H

#include "Condition.h"
//#include "State.h"


class Transition {
private:
	// some actions
	class State* targetState;
	class Condition* condition;

public:
	Transition(Condition* condition_, State* targetState_);
	~Transition();

	bool isTriggered();
	State* getTargetState() { return targetState; }
};

#endif // TRANSITION //