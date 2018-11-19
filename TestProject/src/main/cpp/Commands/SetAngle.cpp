#include "Commands/SetAngle.h"
#include "Robot.h"
#include "OI.h"
#include <cmath>

SetAngle::SetAngle() {
    Requires(Robot::_intake);
}

void SetAngle::Initialize() {}

void SetAngle::Execute() {
    Robot::_intake->SetAngle(abs(Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(1)) > .05) ? Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(1)) : 0); // 0 = left, 1 = right
}

bool SetAngle::IsFinished() { 
    
    return false;
}

void SetAngle::End() {
    
    Robot::_intake->SetAngle(0);
}

void SetAngle::Interrupted() {

}



