#include "Commands/Clamp.h"
#include "Robot.h"
#include "OI.h"

Clamp::Clamp() {
    Requires(Robot::_intake);
}

void Clamp::Initialize() {}

void Clamp::Execute() {
    Robot::_intake->Clamp(gamepad.GetBumper(0));
}

bool Clamp::IsFinished() { return false; }

void Clamp::End() {
    Robot::_intake->Clamp(false);

}

void Clamp::Interrupted() {}



