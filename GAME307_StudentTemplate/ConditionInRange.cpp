#include "ConditionInRange.h"

#include "Character.h"
using namespace MATH;


bool ConditionInRange::test() {
    float thredholdDistance = 2.0f;
    if (VMath::distance(owner->getPlayerPos(), owner->getPos()) < thredholdDistance) {
        return true;
    }
    return false;
}
