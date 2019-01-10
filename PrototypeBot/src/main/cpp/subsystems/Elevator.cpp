#include "subsystems/Elevator.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {
    liftA = new frc::VictorSP(INTAKE_CUBE_MOTOR_A);
    liftB = new frc::VictorSP(INTAKE_CUBE_MOTOR_B);

    encoderElevator = new frc::Encoder(ENCODER_LIFT_A, ENCODER_LIFT_B, false, frc::Encoder::k1X);
}

void Elevator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ElevatorCommandTele());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.