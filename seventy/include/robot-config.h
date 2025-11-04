#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "TFlipFlop.h"

using namespace vex;

extern brain Brain;
extern motor LeftMotor;
extern motor RightMotor;
extern drivetrain Drivetrain;
extern motor ClawMotor;
extern motor ArmMotor;
extern controller Gamepad;
extern TFlipFlop ClawMotorToggle;

void vexcodeInit(void);

#endif