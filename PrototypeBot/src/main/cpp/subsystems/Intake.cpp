#include "subsystems/Intake.h"

#include "RobotMap.h"

#include "Calculations/IntakeCalculations.h"

Intake::Intake() : frc::Subsystem("Intake") {
    intakeA.SetSafetyEnabled(false);
    intakeB.SetSafetyEnabled(false);
    // angle.SetSafetyEnabled(false);
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

/*
void Intake::setAngleSpeed(double power) {
    angle.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, power);
}
*/

void Intake::setSolenoid(double output) {
    solenoid.Set(output == 1);
}