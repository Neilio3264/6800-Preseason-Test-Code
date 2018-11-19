#include "Commands/IntakeOut.h"
#include "Robot.h"

IntakeOut::IntakeOut() {
    Requires(Robot::_intake);
}

void IntakeOut::Initialize() {}

void IntakeOut::Execute() {
    Robot::_intake->SetIntakeSpeedOut(gamepad.GetTriggerAxis(0));
}

bool IntakeOut::IsFinished() { return false; }

void IntakeOut::End() {

    Robot::_intake->SetIntakeSpeedOut(0);

}

void IntakeOut::Interrupted() {}



