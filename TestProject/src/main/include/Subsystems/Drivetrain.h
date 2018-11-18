#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "VictorSP.h"
#include "RobotMap.h"

class Drivetrain : public Subsystem {
private:

	VictorSP *_leftDrive;
    VictorSP *_rightDrive;

	RobotDrive *_drive;

	Solenoid *_shifter;

	bool _closedLoop = 0;
public:
	Drivetrain();

	PowerDistributionPanel* m_pdp;

	void InitDefaultCommand();
	void SetLeft(float val);
	void SetRight(float val);

	void SetGear(bool low);
};

#endif  // Drivetrain_H