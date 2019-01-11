#include "../../include/commands/DrivetrainCommandTele.h"

#include "Robot.h"

DrivetrainCommandTele::DrivetrainCommandTele() {
    Requires(Robot::_drivetrain);
    calculations = new DrivetrainCalculations();
}

void DrivetrainCommandTele::Initialize() {

}

void DrivetrainCommandTele::Execute() {
    left = calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[0];
    right = calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[1];

    Robot::_drivetrain->TankDrive(left, right);
    // Robot::_drivetrain->setMotorLeft(calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[0]);
    // Robot::_drivetrain->setMotorRight(calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[1]);
}

bool DrivetrainCommandTele::IsFinished() { return false; }

void DrivetrainCommandTele::End() {

}

void DrivetrainCommandTele::Interrupted() {}