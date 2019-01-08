#include "commands/IntakeCommandTele.h"

IntakeCommandTele::IntakeCommandTele() {
    Requires(Robot::_intake);
    intakeA = new frc::Spark(DRIVE_LEFTMOTOR);
    intakeB = new frc::Spark(DRIVE_RIGHTMOTOR);
    angle = new WPI_TalonSRX(INTAKE_ANGLE_MOTOR);
    solenoid = new frc::Solenoid(CLAMPER);
}

void IntakeCommandTele::Initialize() {}

void IntakeCommandTele::Execute() {
    // intakeA->Set(1);
    intakeA->Set(Robot::_intake->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[0]);
    intakeB->Set(Robot::_intake->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[0]);
    angle->Set(ControlMode::PercentOutput, Robot::_intake->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[2]);
    solenoid->Set(Robot::_intake->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[1] == 1 ? true : false);
} 

bool IntakeCommandTele::IsFinished() { return false; }

void IntakeCommandTele::End() {
}

void IntakeCommandTele::Interrupted() {}