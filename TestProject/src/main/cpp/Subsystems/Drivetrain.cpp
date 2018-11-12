#include "Subsystems/Drivetrain.h"
#include "RobotMap.h"

Drivetrain *Drivetrain::m_instance = 0;

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

    leftDrive = new VictorSP(DRIVE_LEFTMOTOR);
    rightDrive = new VictorSP(DRIVE_RIGHTMOTOR);

	//Set Motors 2&3 on both sides to follow Left/Right motor 1

	m_drive = new RobotDrive(leftDrive, rightDrive);

	//PDP
	m_pdp = new PowerDistributionPanel();
}

Drivetrain* Drivetrain::GetInstance() {
	if (m_instance ==  0) {
		m_instance = new Drivetrain();
	}
	return m_instance;
}

void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::Tank(float leftstick, float rightstick) {
	m_drive->TankDrive(leftstick,rightstick);
}

void Drivetrain::SetLeft(float val) {
	m_leftMotor1->Set(val);
	frc::SmartDashboard::PutNumber("SetLeft",val);
}


void Drivetrain::SetRight(float val) {
	m_rightMotor1->Set(val);
	frc::SmartDashboard::PutNumber("SetRight",val);
}

//Returns velocities in RPM
double Drivetrain::GetRightVelocity() {
	return m_rightMotor1->GetSpeed();
}

double Drivetrain::GetLeftVelocity() {
	return m_leftMotor1->GetSpeed();
}

int Drivetrain::GetLeftDistance() {
	return m_leftMotor1->GetEncPosition();
}

double Drivetrain::GetLeftThrottle() {
	return m_leftMotor1->GetOutputVoltage();
}

double Drivetrain::GetRightThrottle() {
	return m_rightMotor1->GetOutputVoltage();
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