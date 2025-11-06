#include "SlewController.h"
#include "vex.h"
#include "robot-config.h"

//by chatgpt

SlewController::SlewController(double accel, double decel, double loop_ms) : accelRate(accel), decelRate(decel), loopTime(loop_ms), lastUpdate(0.0) {}

double SlewController::update(double target) {
    double now = Brain.Timer.time(msec);
    double delta_time = now - lastUpdate;
    if (delta_time <= 0.0) delta_time = loopTime; // fallback if first call
    lastUpdate = now;

    double diff = target - current;

    // Scale step size based on time delta
    double accelStep = accelRate * (delta_time / loopTime);
    double decelStep = decelRate * (delta_time / loopTime);

    // Determine if we're increasing speed magnitude (accelerating)
    bool accelerating = std::abs(target) > std::abs(current);

    // Select proper step based on acceleration or deceleration
    double step = accelerating ? accelStep : decelStep;

    // Handle direction change — always decelerate first
    if ((target * current) < 0)
        step = decelStep;

    // Apply the step safely toward target
    if (std::abs(diff) <= step) {
        current = target;
    } else {
        current += (diff > 0 ? step : -step);

        // Optional: snap to 0 if crossing through zero to avoid flicker
        if ((current * (current - (diff > 0 ? step : -step))) < 0)
            current = 0;
    }

    return current;
}


void SlewController::reset(double value) { current = value; }


double SlewController::get() const { return current; }
