#include "../../include/commands/DrivetrainCommandTele.h"

#include "Robot.h"

DrivetrainCommandTele::DrivetrainCommandTele() {
    Requires(&Robot::_drivetrain);
}

void DrivetrainCommandTele::Initialize() {

}

void DrivetrainCommandTele::Execute() {

    auto& leftJoystick = Robot::_oi.getLeftJoyDrive();
    auto& rightJoystick = Robot::_oi.getRightJoyDrive();
    calculationsDrivetrain.CalculateNextOutput(drivetrainOutputs, sizeof(drivetrainOutputs), leftJoystick.GetY(), rightJoystick.GetY(), false);
    
    Robot::_drivetrain.TankDrive(-drivetrainOutputs[0], -drivetrainOutputs[1]);
}

bool DrivetrainCommandTele::IsFinished() { return false; }

void DrivetrainCommandTele::End() {

}

void DrivetrainCommandTele::Interrupted() {}