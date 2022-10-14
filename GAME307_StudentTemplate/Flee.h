#ifndef FLEE_H
#define FLEE_H
#include "SteeringBehaviour.h"


class Flee : public SteeringBehaviour {
protected:
	Body* target;
	// SteeringBehaviour has "character" and "result"
    // so "target" is only needed here

	float maxAcceleration;

public:
	Flee(Body* character_, Body* target_);
	virtual ~Flee();
	SteeringOutput* getSteering();
};

#endif // FLEE_H //