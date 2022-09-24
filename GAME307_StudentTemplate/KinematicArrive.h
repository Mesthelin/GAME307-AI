#ifndef KINEMATIC_ARRIVE_H
#define KINEMATIC_ARRIVE_H
#include "Body.h"
#include "KinematicSteeringOutput.h"
#include "StaticBody.h"
#include "Vector.h"
#include "VMath.h"


using namespace MATH;
class KinematicArrive {
private:
	KinematicSteeringOutput* result;
	Body* character;
	Body* target;

	float radius;
	float timeToTarget;

public:
	KinematicArrive(Body* character_, Body* target_);
	~KinematicArrive();
	KinematicSteeringOutput* getSteering(); // return ptr to KimenaticSteeringOutput
};

#endif //  KINEMATICE_ARRIVE_H
