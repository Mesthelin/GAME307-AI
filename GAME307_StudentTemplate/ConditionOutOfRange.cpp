#include "ConditionOutOfRange.h"

#include "Character.h"
#include "VMath.h"
using namespace MATH;


bool ConditionOutOfRange::test() {
    float thresholdDistance = 3.5f;
    if (VMath::distance(owner->getPlayerPos(), owner->getPos()) > thresholdDistance) {
        return true;
    }
    return false;
}
