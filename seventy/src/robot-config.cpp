#include "vex.h"
#include "quick-config.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;
motor LeftMotor = motor(LEFT_DRIVE_MOTOR_PORT, false);
motor RightMotor = motor(RIGHT_DRIVE_MOTOR_PORT, true);
drivetrain Drivetrain = drivetrain(LeftMotor, RightMotor, 319.18, 355.6, 177.8, mm, 1);
motor ClawMotor = motor(CLAW_MOTOR_PORT, true);
motor ArmMotor = motor(ARM_MOTOR_PORT, ratio18_1, false);
controller Gamepad = controller();
TFlipFlop ClawMotorToggle = TFlipFlop();

void vexcodeInit(void) {
    ArmMotor.setVelocity(100, rpm);
    ClawMotor.setVelocity(100, rpm);
}