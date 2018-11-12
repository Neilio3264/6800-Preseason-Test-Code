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

	Drivetrain();
	static Drivetrain *m_instance;

	bool m_closedLoop = 0;
public:
	PowerDistributionPanel* m_pdp;
	static Drivetrain* GetInstance();
	void InitDefaultCommand();
	void Tank(float leftstick, float rightstick);
	void SetLeft(float val);
	void SetRight(float val);

	double GetRobotCurrent(double val);
	double GetRobotPower(double val);
	double GetRobotEnergy(double val);
};

#endif  // Drivetrain_H