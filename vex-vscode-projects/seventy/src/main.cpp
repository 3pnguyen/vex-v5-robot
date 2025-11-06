#include "vex.h"
#include "robot-config.h"
#include <algorithm>
#include <cmath>
#include "quick-config.h"

using namespace vex;

int main() {
  vexcodeInit();
  
  while (true) {
    int raw_forward_velocity = -Gamepad.Axis3.position() * DRIVE_P_COSNT;
    int forward_velocity = 0;
    if (raw_forward_velocity != 0) forward_velocity = ((raw_forward_velocity == std::abs(raw_forward_velocity)) ? 1 : -1) * std::min(std::max(std::abs(raw_forward_velocity), DRIVE_MIN_SPEED), DRIVE_MAX_SPEED);
    forward_velocity = DriveAcceleration.update(forward_velocity);
    int raw_turn_velocity = Gamepad.Axis4.position() * TURN_P_CONST;
    int turn_velocity = 0;
    if (raw_turn_velocity != 0) turn_velocity = ((raw_turn_velocity == std::abs(raw_turn_velocity)) ? 1 : -1) * std::min(std::max(std::abs(raw_turn_velocity), TURN_MIN_SPEED), TURN_MAX_SPEED);
    bool claw_grip = Gamepad.ButtonX.PRESSED;
    bool claw_grip_manual = Gamepad.ButtonY.pressing();
    bool claw_release_manual = Gamepad.ButtonA.pressing();
    bool raise_arm = Gamepad.ButtonL1.pressing();
    bool lower_arm = Gamepad.ButtonL2.pressing();

    if (raise_arm && !lower_arm) ArmMotor.spin(forward);
    else if (lower_arm && !raise_arm) ArmMotor.spin(reverse);
    else ArmMotor.stop();

    ClawMotorToggle.clock_edge(claw_grip);
    if ((claw_grip_manual && !claw_release_manual) || ClawMotorToggle.get_state()) ClawMotor.spin(forward);
    else if (claw_release_manual && !claw_grip_manual) ClawMotor.spin(reverse);
    else ClawMotor.stop();

    if (std::abs(raw_forward_velocity) > std::abs(raw_turn_velocity)) Drivetrain.drive(forward, forward_velocity, rpm);
    else Drivetrain.turn(right, turn_velocity, rpm);

    wait(5, msec);
  }
}