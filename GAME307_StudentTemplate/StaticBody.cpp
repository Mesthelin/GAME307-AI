#include "StaticBody.h"

void StaticBody::Update(float deltaTime, KinematicSteeringOutput* steering) {

	// update using the base class
	Body::Update(deltaTime);
	newOrientation();

	// then ... do the steering
	vel = steering->velocity;
	rotation = steering->rotation;

	// clip to max speed
	if (VMath::mag(vel) > maxSpeed) {
		vel = VMath::normalize(vel) * maxSpeed;
	}

	// clip to max rotation
	if (rotation > maxRotation) {
		rotation = maxRotation;
	}
}

void StaticBody::newOrientation() {
	if (VMath::mag(vel) > 0.0f) {
		orientation = atan2(-vel.y, vel.x);
	}
}