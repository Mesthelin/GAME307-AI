#include "Seek.h"


Seek::Seek(Body *character_, Body *target_) {
	character = character_;
	target = target_;
	result = new SteeringOutput();
}

Seek::~Seek() {}

SteeringOutput *Seek::getSteering() {
	// direction to the target
	result->linear = target->getPos() - character->getPos();

	// go full speed along this direction
	result->linear = VMath::normalize(result->linear) * character->getMaxAcceleration();
	
	result->angular = 0.0f;
	return result;
}
