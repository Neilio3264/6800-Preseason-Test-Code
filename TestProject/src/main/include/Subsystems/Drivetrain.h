#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "../Utilities/PIDControl.h"

class Drivetrain : public Subsystem {
private:

	static double teleOutput[3];
	static double autoOutput[2];

	double p_val_straight;
	double i_val_straight;
	double d_val_straight;

    double dt;

    PIDControl drivetrainPID_forward;
	PIDControl drivetrainPID_turn;
	PIDControl drivetrainPID_straight;	

public:
	Drivetrain();
	double * CalculateNextOutputTele(double leftJoyVal, double rightJoyVal, bool shifterVal);
	double * CalculateNextOutputAuto(double targetEncoder, double targetGyro, double currEncoder, 
										double currGyro, bool turn, double dt, double p, double i, double d, 
										double accuracy);


};

#endif  // Drivetrain_H