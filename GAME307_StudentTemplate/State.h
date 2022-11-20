#ifndef STATE_H
#define STATE_H

#include <list>
//#include "Transition.h"
using namespace std;

enum class STATE { SEEK, DO_NOTHING } // added

;
class Transition;
class State {
private:
	list<Transition*> transitions;
	STATE name; // added
	// some actions
	// getActions();
	// getEntryActions();
	// getExitActions();

public:
	State(STATE name_) { name = name_; } // added arguments
	~State() {}

	list<Transition*> getTransitions() { return transitions; }
	void addTransition(Transition* transition);
	STATE getName() { return name; }
};

#endif // STATE_H //