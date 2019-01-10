#include "commands/IntakeCommandTele.h"

#include "Robot.h"

IntakeCommandTele::IntakeCommandTele() {
    Requires(Robot::_intake);
    calculations = new IntakeCalculations();
    /*
    intakeA = new frc::Spark(DRIVE_LEFTMOTOR);
    intakeB = new frc::Spark(DRIVE_RIGHTMOTOR);
    angle = new WPI_TalonSRX(INTAKE_ANGLE_MOTOR);
    solenoid = new frc::Solenoid(CLAMPER);
    */
}

void IntakeCommandTele::Initialize() {}

void IntakeCommandTele::Execute() {
    // intakeA->Set(1);
    Robot::_intake->intakeA->Set(calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[0]);
    Robot::_intake->intakeB->Set(calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[0]);
    Robot::_intake->angle->Set(ControlMode::PercentOutput, calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[2]);
    Robot::_intake->solenoid->Set(calculations->CalculateNextOutput(Robot::_oi->getGamepad()->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetY(frc::GenericHID::JoystickHand::kRightHand), Robot::_oi->getGamepad()->GetYButton(), Robot::_oi->getGamepad()->GetBumper(frc::GenericHID::JoystickHand::kLeftHand), 0)[1] == 1 ? true : false);
} 

bool IntakeCommandTele::IsFinished() { return false; }

void IntakeCommandTele::End() {
}

void IntakeCommandTele::Interrupted() {}