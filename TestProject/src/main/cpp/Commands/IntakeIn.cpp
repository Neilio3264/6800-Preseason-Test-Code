#include "Commands/IntakeIn.h"
#include "Robot.h"

IntakeIn::IntakeIn() {
    Requires(Robot::_intake);
}

void IntakeIn::Initialize() {}

void IntakeIn::Execute() {
    Robot::_intake->SetIntakeSpeedIn(gamepad.GetTriggerAxis(1));
}

bool DriveWithJoystick::IsFinished() { return false; }

void DriveWithJoystick::End() {

    Robot::_intake->SetIntakeSpeedIn(0);

}

void DriveWithJoystick::Interrupted() {}



