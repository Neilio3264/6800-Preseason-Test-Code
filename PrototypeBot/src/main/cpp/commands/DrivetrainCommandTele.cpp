#include "../../include/commands/DrivetrainCommandTele.h"

DrivetrainCommandTele::DrivetrainCommandTele() {
    Requires(Robot::_drivetrain);
    motorLeft = new frc::VictorSP(DRIVE_LEFTMOTOR);
    motorRight = new frc::VictorSP(DRIVE_RIGHTMOTOR);
}

void DrivetrainCommandTele::Initialize() {}

void DrivetrainCommandTele::Execute() {
    motorLeft->Set(Robot::_drivetrain->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[0]);
    motorRight->Set(Robot::_drivetrain->CalculateNextOutput(Robot::_oi->getLeftJoyDrive()->GetY(), Robot::_oi->getRightJoyDrive()->GetY(), false)[1]);
}

bool DrivetrainCommandTele::IsFinished() { return false; }

void DrivetrainCommandTele::End() {

}

void DrivetrainCommandTele::Interrupted() {}