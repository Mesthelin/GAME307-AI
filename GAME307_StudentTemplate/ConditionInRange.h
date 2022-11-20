#ifndef CONDITION_IN_RANGE_H
#define CONDITION_IN_RANGE_H

#include "Condition.h"


class ConditionInRange : public Condition {
private:

public:
	ConditionInRange(Character* owner_) : Condition(owner_) {
	// put more stuff in here if need in constructor
	
	}

	bool test();

};

#endif // CONDITION_IN_RANGE_H //