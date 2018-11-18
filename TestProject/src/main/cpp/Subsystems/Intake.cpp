#include "Subsystems/Intake.h"

#include "RobotMap.h"
#include <cmath>


Intake::Intake() : Subsystem("Intake") {

    _intakeA = new Spark(INTAKE_CUBE_MOTOR_A);
    _intakeB = new Spark(INTAKE_CUBE_MOTOR_B);
    _angle = new Talon(INTAKE_ANGLE_MOTOR);
    _clamp = new Solenoid(CLAMPER);
}

void Clamp(bool isClamped) {
    _clamp.Set(!isClamped); // left_bumper
}

void SetIntakeSpeedIn(double power) {
    _intakeA.Set(power);
    _intakeB.Set(power); // right_trigger
}

void SetIntakeSpeedOut(double power) {
    SetIntakeSpeedIn(-power); // left_trigger
}

void SetAngle(double power) {
    _angle.Set(power); // right_stick y

    // **LIFT IS LEFT STICK Y
}


