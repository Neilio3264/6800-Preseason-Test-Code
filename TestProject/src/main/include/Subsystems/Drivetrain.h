#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "VictorSP.h"
#include "RobotMap.h"

class Drivetrain : public Subsystem {
private:

	VictorSP *leftDrive;
    VictorSP *rightDrive;

	RobotDrive *m_drive;

	bool m_closedLoop = 0;
public:
	Drivetrain();

	PowerDistributionPanel* m_pdp;

	void InitDefaultCommand();
	void Tank(float leftstick, float rightstick);
	void SetLeft(float val);
	void SetRight(float val);

	double GetRobotCurrent(double val);
	double GetRobotPower(double val);
	double GetRobotEnergy(double val);
};

#endif  // Drivetrain_H