#include "Commands/ElevatorMove.h"
#include "Robot.h"
#include "OI.h"

#include <cmath>
#include "../../include/Utilities/Constants.h"

ElevatorMove::ElevatorMove() {
    Requires(Robot::_elevator);
}

void ElevatorMove::Initialize() {}

void ElevatorMove::Execute() {
    Robot::_elevator->Start(abs(Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(0))) > .05 ? Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(0)) : LIFT_BASE_POWER); // 0 = left, 1 = right
}

bool ElevatorMove::IsFinished() { 
    
    return false;
 }

void ElevatorMove::End() {
    
    Robot::_elevator->Stop();
}

void ElevatorMove::Interrupted() {

}



