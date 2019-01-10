#include "subsystems/Drivetrain.h"


Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {}

void Drivetrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  SetDefaultCommand(new DrivetrainCommandTele());
}

void Drivetrain::setMotorLeft(double power) {
    motorLeft->Set(power);
}

void Drivetrain::setMotorRight(double power) {
    motorRight->Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.