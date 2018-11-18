#include "Commands/Shift.h"
#include "Robot.h"

Shift::Shift() {
    Requires(Robot::_drivetrain);
}

void Shift::Initialize() {}

void Shift::Execute() {
    Robot::_drivetrain->SetGear(pedal->WhileHeld());
}

bool Shift::IsFinished() { 
    return false; 
}

void Shift::End() {

    Robot::_drivetrain->SetGear(false);

}

void Shift::Interrupted() {}