#include "Commands/Drive.h"
#include "Robot.h"
#include "Utilities/PIDControl.h"

Drive::Drive(double p, double i, double d, double setpoint, double startValue, double acc) : 
    pid {p, i, d, setpoint, startValue, acc} {
    Requires(Robot::_drivetrain);
}

void Drive::Initialize() {}

void Drive::Execute() {
    Robot::_drivetrain->Start(pid::PIDLoops)
}

bool Drive::IsFinished() { return false; }

void Drive::End() {

}

void Drive::Interrupted() {}



