#include "PlayerInRangeDecision.h"

#include "Character.h"
#include "VMath.h"
using namespace MATH;


bool PlayerInRangeDecision::testValue() {
    // distance to player is less than value
    float thresholdDistance = 3.0f;

    // get player position
    owner->getPos();

    if (VMath::distance(owner->getPlayerPos(), owner->getPos()) < thresholdDistance) {
        cout << "SEEK\n";
        return true;
    };

    cout << "DO_NOTHING\n";
    return false;
}
