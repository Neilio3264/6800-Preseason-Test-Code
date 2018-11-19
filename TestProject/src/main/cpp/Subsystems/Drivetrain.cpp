#include "../../include/Subsystems/Drivetrain.h"
#include "../../include/Commands/DriveWithJoystick.h"

#include "RobotMap.h"
#include <cmath>
#include <WPILib.h>


Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

    _leftDrive = new VictorSP(DRIVE_LEFTMOTOR);
    _rightDrive = new VictorSP(DRIVE_RIGHTMOTOR);

	_shifter = new Solenoid(SHIFTER);

	//PDP
	m_pdp = new PowerDistributionPanel();
}

void Drivetrain::InitDefaultCommand() {
	SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::SetLeft(float val) {
	_leftDrive->Set(val);
	frc::SmartDashboard::PutNumber("SetLeft", val);
}

void Drivetrain::SetRight(float val) {
	_rightDrive->Set(val);
	frc::SmartDashboard::PutNumber("SetRight", val);
}

void Drivetrain::SetGear(bool low) {
	_shifter->Set(low);
}

