#include "Flee.h"


Flee::Flee(Body* character_, Body* target_) {
	character = character_;
	target = target_;
	result = new SteeringOutput();
}

Flee::~Flee() {}

SteeringOutput* Flee::getSteering() {
	// direction to the target
	result->linear = character->getPos() - target->getPos();

	// go full speed along this direction
	result->linear = VMath::normalize(result->linear) * character->getMaxAcceleration();
	
	result->angular = 0.0f;
	return result;
}
