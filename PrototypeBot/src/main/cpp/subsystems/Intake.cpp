#include "subsystems/Intake.h"

#include "RobotMap.h"

#include "Calculations/IntakeCalculations.h"

Intake::Intake() : frc::Subsystem("Intake") {}

void Intake::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new IntakeCommandTele());
}

void Intake::setIntakeSpeed(double power) {
    intakeA -> Set(power);
    intakeB -> Set(power);                                
}

void Intake::setAngleSpeed(double power) {
    angle->Set(power);
}

void Intake::setSolenoid(double output) {
    output == 1 ? solenoid->Set(true) : solenoid->Set(false);
}