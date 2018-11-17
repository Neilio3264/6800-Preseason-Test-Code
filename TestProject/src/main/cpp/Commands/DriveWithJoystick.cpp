#include "Commands/DriveWithJoystick.h"
#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(Robot::_drivetrain);
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
    Robot::_drivetrain->m
}

bool DriveWithJoystick::IsFinished() { return false; }

void DriveWithJoystick::End() {

    Robot::_drivetrain->Tank(0, 0);

}

void DriveWithJoystick::Interrupted() {}



