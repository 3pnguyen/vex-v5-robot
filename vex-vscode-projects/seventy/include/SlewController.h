#ifndef SLEWCONTROLLER_H
#define SLEWCONTROLLER_H

#include "vex.h"

using namespace vex;

class SlewController {
    private:
        double current;
        double accelRate;
        double decelRate;
        double loopTime;
        double lastUpdate;

    public:
        SlewController(double accel, double decel, double loop_ms = 20);

        double update(double target);

        void reset(double value = 0.0);

        double get() const;
};

#endif