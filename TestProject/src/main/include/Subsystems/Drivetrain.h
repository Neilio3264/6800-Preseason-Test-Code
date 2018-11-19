#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "VictorSP.h"
#include <Solenoid.h>
#include "RobotMap.h"
#include "WPILib.h"
#include "PowerDistributionPanel.h"

class Drivetrain : public Subsystem {
private:

	VictorSP *_leftDrive;
    VictorSP *_rightDrive;

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