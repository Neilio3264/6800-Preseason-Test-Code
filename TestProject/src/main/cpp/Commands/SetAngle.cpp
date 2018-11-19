#include "Commands/SetAngle.h"
#include "Robot.h"
#include <cmath>

SetAngle::SetAngle() {
    Requires(Robot::_intake);
}

void SetAngle::Initialize() {}

void SetAngle::Execute() {
    Robot::_intake->SetAngle(abs(gamepad->GetY(1) > .05) ? gamepad->GetY() : 0); // 0 = left, 1 = right
}

bool ElevatorMove::IsFinished() { 
    
    return false;
 }

void ElevatorMove::End() {
    
    Robot::_intake->SetAngle(0);
}

void ElevatorMove::Interrupted() {

}



