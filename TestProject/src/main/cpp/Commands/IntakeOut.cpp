#include "Commands/IntakeOut.h"
#include "Robot.h"
#include "OI.h"

IntakeOut::IntakeOut() {
    Requires(Robot::_intake);
}

void IntakeOut::Initialize() {}

void IntakeOut::Execute() {
    Robot::_intake->SetIntakeSpeedOut(Robot::_oi->getGamepad()->GetTriggerAxis(GenericHID::JoystickHand(0)));
}

bool IntakeOut::IsFinished() { return false; }

void IntakeOut::End() {

    Robot::_intake->SetIntakeSpeedOut(0);

}

void IntakeOut::Interrupted() {}



