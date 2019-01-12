#include "../../include/commands/DrivetrainCommandTele.h"

#include "Robot.h"

DrivetrainCommandTele::DrivetrainCommandTele() {
    Requires(&Robot::_drivetrain);
    calculationsDrivetrain = new DrivetrainCalculations();
}

void DrivetrainCommandTele::Initialize() {

}

void DrivetrainCommandTele::Execute() {

    auto& leftJoystick = Robot::_oi.getLeftJoyDrive();
    auto& rightJoystick = Robot::_oi.getRightJoyDrive();

    left = calculationsDrivetrain->CalculateNextOutput(leftJoystick.GetY(), rightJoystick.GetY(), false)[0];
    right = calculationsDrivetrain->CalculateNextOutput(leftJoystick.GetY(), rightJoystick.GetY(), false)[1];

    Robot::_drivetrain.TankDrive(left, right);
}

bool DrivetrainCommandTele::IsFinished() { return false; }

void DrivetrainCommandTele::End() {

}

void DrivetrainCommandTele::Interrupted() {}