#include "util.h"

double getTurnError(double heading, double target) {
    if(std::max(heading, target) - std::min(heading, target) <= 180) {
        return target - heading;
    }

    else {
        if(heading > target) {
            return target - heading + 360;
        }

        else {
            return target - heading - 360;
        }
    }
}
