#include "Subsystems/Drivetrain.h"
#include "../../include/Commands/DriveWithJoystick.h"

#include "RobotMap.h"
#include <cmath>


Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

    leftDrive = new VictorSP(DRIVE_LEFTMOTOR);
    rightDrive = new VictorSP(DRIVE_RIGHTMOTOR);

	//Set Motors 2&3 on both sides to follow Left/Right motor 1

	m_drive = new RobotDrive(leftDrive, rightDrive);

	//PDP
	m_pdp = new PowerDistributionPanel();
}

void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Tank(float leftstick, float rightstick) {

	m_drive->TankDrive(leftstick, rightstick);
	
}

void Drivetrain::SetLeft(float val) {
	leftDrive->Set(val);
	frc::SmartDashboard::PutNumber("SetLeft",val);
}


void Drivetrain::SetRight(float val) {
	rightDrive->Set(val);
	frc::SmartDashboard::PutNumber("SetRight",val);
}


double Drivetrain::GetRobotCurrent(double val) {
	val = m_pdp->GetTotalCurrent();
	return val;
}

double Drivetrain::GetRobotPower(double val) {
	val = m_pdp->GetTotalPower();
	return val;
}

double Drivetrain::GetRobotEnergy(double val) {
	val = m_pdp->GetTotalEnergy();
	return val;
}