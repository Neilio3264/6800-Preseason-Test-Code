#include "commands/ElevatorCommandTele.h"

#include "Robot.h"

ElevatorCommandTele::ElevatorCommandTele() {
    Requires(Robot::_elevator);

    calculations = new ElevatorCalculations();
}

void ElevatorCommandTele::Initialize() {}

void ElevatorCommandTele::Execute() {
    Robot::_elevator->setLiftMotors(calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetAButton(), Robot::_oi->getGamepad()->GetBButton(), Robot::_oi->getGamepad()->GetXButton(), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kLeftHand), Robot::_elevator->getEncoder()));
    // Robot::_elevator->setLiftMotors(calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetAButton(), Robot::_oi->getGamepad()->GetBButton(), Robot::_oi->getGamepad()->GetXButton(), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kLeftHand), Robot::_elevator->encoderElevator->GetRaw()));
}

bool ElevatorCommandTele::IsFinished() { return false; }

void ElevatorCommandTele::End() {

}

void ElevatorCommandTele::Interrupted() {}