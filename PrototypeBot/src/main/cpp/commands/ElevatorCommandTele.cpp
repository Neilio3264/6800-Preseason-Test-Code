#include "commands/ElevatorCommandTele.h"

#include "Robot.h"

ElevatorCommandTele::ElevatorCommandTele() {
    Requires(&Robot::_elevator);

    calculationsElevator = new ElevatorCalculations();
}

void ElevatorCommandTele::Initialize() {}

void ElevatorCommandTele::Execute() {
    Robot::_elevator.setLiftMotors(calculationsElevator->CalculateNextOutput(Robot::_oi.getGamepad()->GetAButton(), Robot::_oi.getGamepad()->GetBButton(), Robot::_oi.getGamepad()->GetXButton(), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kLeftHand), Robot::_elevator.getEncoder()));
}

bool ElevatorCommandTele::IsFinished() { return false; }

void ElevatorCommandTele::End() {

}

void ElevatorCommandTele::Interrupted() {}