#include "commands/IntakeCommandTele.h"

#include "Robot.h"

IntakeCommandTele::IntakeCommandTele() {
    Requires(&Robot::_intake);
    calculationsIntake = new IntakeCalculations();
}

void IntakeCommandTele::Initialize() {}

void IntakeCommandTele::Execute() {
    Robot::_intake.setIntakeSpeed(calculationsIntake->CalculateNextOutput(Robot::_oi.getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetYButton(), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[0]);
    // Robot::_intake.setAngleSpeed(calculationsIntake->CalculateNextOutput(Robot::_oi.getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetYButton(), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[2]);
    Robot::_intake.setSolenoid(calculationsIntake->CalculateNextOutput(Robot::_oi.getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi.getGamepad()->GetYButton(), Robot::_oi.getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[1]);
} 

bool IntakeCommandTele::IsFinished() { return false; }

void IntakeCommandTele::End() {
}

void IntakeCommandTele::Interrupted() {}