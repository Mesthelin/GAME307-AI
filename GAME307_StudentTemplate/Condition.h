#ifndef CONDITION_H
#define CONDITION_H
// ABSTRACT CLASS ^^^ CANNOT CREATE INSTANCES OF THIS
// this is circular dependency
// #include "Character.h"


class Condition {
protected:
	class Character* owner;

public:
	Condition(Character* owner_) { owner = owner_; }
	~Condition() {}

	virtual bool test() = 0;
};

#endif // CONDITION //