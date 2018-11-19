#include "Commands/ElevatorMove.h"
#include "Robot.h"
#include <cmath>
#include "OI.h"
#include "../../include/Utilities/Constants.h"

ElevatorMove::ElevatorMove() {
    Requires(Robot::_elevator);
}

void ElevatorMove::Initialize() {}

void ElevatorMove::Execute() {
    Robot::_elevator->Start(abs(gamepad->GetY(0) > .05) ? gamepad->GetY() : LIFT_BASE_POWER); // 0 = left, 1 = right
}

bool ElevatorMove::IsFinished() { 
    
    return false;
 }

void ElevatorMove::End() {
    
    Robot::_elevator->Stop();
}

void ElevatorMove::Interrupted() {

}



