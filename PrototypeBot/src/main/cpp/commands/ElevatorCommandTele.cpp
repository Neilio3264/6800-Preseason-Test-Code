#include "commands/ElevatorCommandTele.h"

ElevatorCommandTele::ElevatorCommandTele() {
    Requires(Robot::_elevator);
    liftA = new frc::VictorSP(INTAKE_CUBE_MOTOR_A);
    liftB = new frc::VictorSP(INTAKE_CUBE_MOTOR_B);

    encoderElevator = new frc::Encoder(ENCODER_LIFT_A, ENCODER_LIFT_B, false, frc::Encoder::k1X);

}

void ElevatorCommandTele::Initialize() {}

void ElevatorCommandTele::Execute() {
    liftA->Set(Robot::_elevator->CalculateNextOutput(Robot::_oi->getGamepad()->GetAButton(), Robot::_oi->getGamepad()->GetBButton(), Robot::_oi->getGamepad()->GetXButton(), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kLeftHand), encoderElevator->GetRaw()));
    liftB->Set(Robot::_elevator->CalculateNextOutput(Robot::_oi->getGamepad()->GetAButton(), Robot::_oi->getGamepad()->GetBButton(), Robot::_oi->getGamepad()->GetXButton(), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kLeftHand), encoderElevator->GetRaw()));
}

bool ElevatorCommandTele::IsFinished() { return false; }

void ElevatorCommandTele::End() {

}

void ElevatorCommandTele::Interrupted() {}