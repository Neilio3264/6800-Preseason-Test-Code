#include "subsystems/Intake.h"

#include "RobotMap.h"

#include "Calculations/IntakeCalculations.h"

Intake::Intake() : frc::Subsystem("Intake") {
    solenoid = new frc::Solenoid(2);
    encoderIntake = new frc::Encoder(1, 2, false, frc::Encoder::k1X);
}

void Intake::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new IntakeCommandTele());
}

void Intake::setIntakeSpeed(double power) {
    intakeA.Set(power);
    intakeB.Set(power);                                
}

void Intake::setAngleSpeed(double power) {
    angle->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power);
}

void Intake::setSolenoid(double output) {
    output == 1 ? solenoid->Set(true) : solenoid->Set(false);
}