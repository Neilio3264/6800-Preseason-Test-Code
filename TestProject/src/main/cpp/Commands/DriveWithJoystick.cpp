#include "Commands/DriveWithJoystick.h"
#include "Robot.h"
#include "OI.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(Robot::_drivetrain);
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
    Robot::_drivetrain->SetLeft(Robot::_oi->getLeftJoyDrive()->GetX());
    Robot::_drivetrain->SetRight(Robot::_oi->getLeftJoyDrive()->GetY());
}

bool DriveWithJoystick::IsFinished() { return false; }

void DriveWithJoystick::End() {

    Robot::_drivetrain->SetLeft(0);
    Robot::_drivetrain->SetRight(0);

}

void DriveWithJoystick::Interrupted() {}



