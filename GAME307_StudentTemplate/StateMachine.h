#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Condition.h"
#include "ConditionInRange.h"
#include "ConditionOutOfRange.h"
#include "State.h"
#include "Transition.h"


class StateMachine {
private:
	State* initialState;
	State* currentState;
	class Character* owner;

public:
	StateMachine(Character* owner_) { owner = owner_; }
	~StateMachine() {}

	void setInitialState(State* initial_);
	void update();
	STATE getCurrentStateName() { return currentState->getName(); } // added
};

#endif // STATE_MACHINE_H //