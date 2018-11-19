#include "../../include/Subsystems/Elevator.h"

#include "RobotMap.h"
#include <cmath>
#include <WPILib.h>


Elevator::Elevator() : Subsystem("Elevator") {

    liftMotorA = new VictorSP(LIFT_MOTOR_A);
    liftMotorB = new VictorSP(LIFT_MOTOR_B);

}

void Elevator::InitDefaultCommand() {
	// SetDefaultCommand(new DriveWithJoystick());
}

void Elevator::Start(double power) {
    liftMotorA->Set(power);
    liftMotorB->Set(power);
}

void Elevator::Stop() {
    Start(0);
}