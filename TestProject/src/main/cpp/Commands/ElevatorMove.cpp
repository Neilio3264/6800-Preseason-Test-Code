#include "Commands/ElevatorMove.h"
#include "Robot.h"
#include "OI.h"
#include "RobotMap.h"

#include <cmath>
#include "../../include/Utilities/Constants.h"

ElevatorMove::ElevatorMove() : liftMotorA {LIFT_MOTOR_A}, liftMotorB {LIFT_MOTOR_B},
    liftEncoder {ENCODER_LIFT_A, ENCODER_LIFT_B} {
    Requires(Robot::_elevator);
}

void ElevatorMove::Initialize() {}

void ElevatorMove::Execute() {
    double val = Robot::_elevator->CalculateNextOutput(false, false, false, Robot::_oi->getGamepad->GetY(GenericHID::JoystickHand(0)), liftEncoder.Get());
    liftMotorA.Set(val);
    liftMotorB.Set(val);
    //Robot::_elevator->Start(abs(Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(0))) > .05 ? Robot::_oi->getGamepad()->GetY(GenericHID::JoystickHand(0)) : LIFT_BASE_POWER); // 0 = left, 1 = right
}

bool ElevatorMove::IsFinished() { 
    return false;
 }

void ElevatorMove::End() {
    double val = Robot::_elevator->CalculateNextOutput(false, false, false, 0, 0);
    liftMotorA.Set(val);
    liftMotorB.Set(val);
}

void ElevatorMove::Interrupted() {

}