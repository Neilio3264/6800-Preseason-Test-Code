#include "../../include/commands/DrivetrainCommandTele.h"

#include "Robot.h"

DrivetrainCommandTele::DrivetrainCommandTele() {
    Requires(Robot::_drivetrain);
    calculations = new DrivetrainCalculations();
}

void DrivetrainCommandTele::Initialize() {
}

void DrivetrainCommandTele::Execute() {
    Robot::_drivetrain->setMotorLeft(calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[0]);
    Robot::_drivetrain->setMotorRight(calculations->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[1]);
}

bool DrivetrainCommandTele::IsFinished() { return false; }

void DrivetrainCommandTele::End() {

}

void DrivetrainCommandTele::Interrupted() {}