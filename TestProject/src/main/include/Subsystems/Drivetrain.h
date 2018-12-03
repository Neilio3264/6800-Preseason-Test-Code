#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "../Utilities/PIDControl.h"

class Drivetrain : public Subsystem {
private:

	double leftJoystick;
	double rightJoystick;
	bool lowGear;

	int encoder;
	double gyro;

	static double teleOutput[3];
	static double autoOutput[2];

	double p_val_straight;
	double i_val_straight;
	double d_val_straight;

	double p_val_forward;
	double i_val_forward;
	double d_val_forward;
	double accuracy_forward;

	double p_val_turn;
	double i_val_turn;
	double d_val_turn;
	double accuracy_turn;

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