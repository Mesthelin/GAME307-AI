#ifndef SEEK_H
#define SEEK_H
#include "SteeringBehaviour.h"


class Seek : public SteeringBehaviour {
protected:
	Body* target;
	// SteeringBehaviour has "character" and "result"
	// so "target" is only needed here

	float maxAcceleration;
	
public:
	Seek(Body *character_, Body *target_);
	virtual ~Seek();
	SteeringOutput *getSteering();
};

#endif // SEEK_H //