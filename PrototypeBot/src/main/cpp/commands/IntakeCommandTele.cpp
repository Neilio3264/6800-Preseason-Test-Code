#include "commands/IntakeCommandTele.h"

#include "Robot.h"

IntakeCommandTele::IntakeCommandTele() {
    Requires(&Robot::_intake);
}

void IntakeCommandTele::Initialize() {}

void IntakeCommandTele::Execute() {
    calculationsIntake.CalculateNextOutput(intakeOutputs, sizeof(intakeOutputs), Robot::_oi.getGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi.getGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad().GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad().GetYButton(), Robot::_oi.getGamepad().GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0);
    Robot::_intake.setIntakeSpeed(intakeOutputs[0]);
    Robot::_intake.setIntakeSpeed(intakeOutputs[1]);
    Robot::_intake.setIntakeSpeed(intakeOutputs[2]);
} 

bool IntakeCommandTele::IsFinished() { return false; }

void IntakeCommandTele::End() {
}

void IntakeCommandTele::Interrupted() {}