#include "SlewController.h"
#include "vex.h"
#include "robot-config.h"

SlewController::SlewController(double accel, double decel, double loop_ms) : accelRate(accel), decelRate(decel), loopTime(loop_ms), lastUpdate(0.0) {}

double SlewController::update(double target) {
    double now = Brain.Timer.time(msec);\
    double delta_time = now - lastUpdate;
    if (delta_time <= 0.0) delta_time = loopTime;
    lastUpdate = now;
    double diff = target - current;
    double accelStep = accelRate * (delta_time / loopTime);
    double decelStep = decelRate * (delta_time / loopTime);
    if (diff > accelStep) current += accelStep;
    else if (diff < -decelStep) current -= decelStep;
    else current = target;
    return current;
}

void SlewController::reset(double value) { current = value; }

double SlewController::get() const { return current; }