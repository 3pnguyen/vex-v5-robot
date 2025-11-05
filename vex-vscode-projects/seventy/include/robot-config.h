#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "TFlipFlop.h"
#include "SlewController.h"

using namespace vex;

class TFlipFlop;
class SlewController;

extern brain Brain;
extern motor LeftMotor;
extern motor RightMotor;
extern drivetrain Drivetrain;
extern motor ClawMotor;
extern motor ArmMotor;
extern controller Gamepad;
extern TFlipFlop ClawMotorToggle;
extern SlewController DriveAcceleration;

void vexcodeInit(void);

#endif