#ifndef KINEMATIC_SEEK_H
#define KINEMATIC_SEEK_H
#include "Body.h"
#include "KinematicSteeringOutput.h"
#include "StaticBody.h"
#include "Vector.h"
#include "VMath.h"


using namespace MATH;
class KinematicSeek {
private:
	KinematicSteeringOutput* result;
	Body* character;
	Body* target;

public:
	KinematicSeek(Body* character_, Body* target_);
	~KinematicSeek();
	KinematicSteeringOutput* getSteering(); // return ptr to KimenaticSteeringOutput

};

#endif // KINEMATIC_SEEK_H
