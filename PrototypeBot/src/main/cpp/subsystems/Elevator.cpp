#include "subsystems/Elevator.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {
  liftA.SetSafetyEnabled(false);
  liftB.SetSafetyEnabled(false);
}

void Elevator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ElevatorCommandTele());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Elevator::setLiftMotors(double power) {
  liftA.Set(power);
  liftB.Set(power);
}

double Elevator::getEncoder() {
  return (double)encoderElevator.GetRaw();
}