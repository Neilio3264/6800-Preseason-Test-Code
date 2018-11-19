#include "Commands/IntakeIn.h"
#include "Robot.h"
#include "OI.h"

IntakeIn::IntakeIn() {
    Requires(Robot::_intake);
}

void IntakeIn::Initialize() {}

void IntakeIn::Execute() {
    Robot::_intake->SetIntakeSpeedIn(Robot::_oi->getGamepad()->GetTriggerAxis(GenericHID::JoystickHand(1)));
}

bool IntakeIn::IsFinished() { return false; }

void IntakeIn::End() {

    Robot::_intake->SetIntakeSpeedIn(0);

}

void IntakeIn::Interrupted() {}



