#include "Commands/DriveWithJoystick.h"
#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(Drivetrain::GetInstance());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
    Drivetrain::GetInstance()->Tank(OI::GetInstance()->leftJoyDrive->GetRawAxis(1), OI::GetInstance()->rightJoyDrive->GetRawAxis(1));
}

bool DriveWithJoystick::IsFinished() { return false; }

void DriveWithJoystick::End() {

    Drivetrain::GetInstance()->Tank(0, 0);

}

void DriveWithJoystick::Interrupted() {}



