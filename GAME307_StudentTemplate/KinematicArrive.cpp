#include "KinematicArrive.h"


KinematicArrive::KinematicArrive(Body* character_, Body* target_) {
	
	character = character_;
	target = target_;
	result = new KinematicSteeringOutput();

	radius = 0.0f;
	timeToTarget = 1.25f;
}

KinematicArrive::~KinematicArrive() {

	if (result) { delete result; }
}

KinematicSteeringOutput* KinematicArrive::getSteering() {
	result->velocity = target->getPos() - character->getPos();

	if (VMath::mag(result->velocity) < radius) {
		return NULL;
	}

	result->velocity /= timeToTarget;
	
	// clip to maxSpeed
	if (VMath::mag(result->velocity) > character->getMaxSpeed()) {
		// go full speed along this direction
		result->velocity = VMath::normalize(result->velocity);
		result->velocity = result->velocity * character->getMaxSpeed();
	}

	result->rotation = 0.0f;
	return result;
}
