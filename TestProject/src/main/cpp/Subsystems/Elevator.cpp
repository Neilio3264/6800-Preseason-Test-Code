#include "Subsystems/Elevator.h"

#include "RobotMap.h"
#include <cmath>


ELevator::ELevator() : Subsystem("Elevator") {

    liftMotorA = new VictorSP(LIFT_MOTOR_A);
    liftMotorB = new VictorSP(LIFT_MOTOR_B);

}

void Elevator::InitDefaultCommand() {
	// SetDefaultCommand(new DriveWithJoystick());
}

void Start(double power) {
    liftMotorA.Set(power);
    liftMotorB.Set(power);
}

void Stop() {
    Start(0);
}