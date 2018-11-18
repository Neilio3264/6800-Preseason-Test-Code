#include "Commands/DriveWithJoystick.h"
#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(Robot::_drivetrain);
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
    Robot::_drivetrain->Tank(leftJoyDrive.GetRawAxis(1), rightJoyDrive.GetRawAxis(1));
}

bool DriveWithJoystick::IsFinished() { return false; }

void DriveWithJoystick::End() {

    Robot::_drivetrain->Tank(0, 0);

}

void DriveWithJoystick::Interrupted() {}



