#include "Drivetrain.h"
#include "../../include/Subsystems/Drivetrain.h"
#include <cmath>


Drivetrain::Drivetrain() : Subsystem("Drivetrain"){
    p_val_straight = .5;
	i_val_straight = .2;
	d_val_straight = .1;


    drivetrainPID_forward = new PIDControl(); // TODO: get real values for these PID constants
	drivetrainPID_turn = new PIDControl();
	drivetrainPID_straight = new PIDControl();
    dt = 0.02;

}

double *Drivetrain::CalculateNextOutputTele(double leftJoyVal, double rightJoyVal, bool shift) {
	
	
	teleOutput[0] = leftJoyVal > .05 ? leftJoyVal : 0;
	teleOutput[1] = rightJoyVal > .05 ? rightJoyVal : 0;
	teleOutput[2] = shift ? 1 : 0;

	return teleOutput;
	
}


double *Drivetrain::CalculateNextOutputAuto(double targetEncoder, double targetGyro, double currEncoder, double currGyro, bool turn, double dt, double p, double i, double d, double accuracy) {
	if(turn) {
		autoOutput[0] = drivetrainPID_turn.PID_Loop(targetGyro, p, i, d, currGyro, accuracy, dt);
		autoOutput[1] = -autoOutput[0];
	} else {
		autoOutput[0] = drivetrainPID_forward.PID_Loop(targetEncoder, p, i, d, currEncoder, accuracy, dt) + drivetrainPID_turn.PID_Loop(targetGyro, p_val_straight, i_val_straight, d_val_straight, currGyro, accuracy, dt);
		autoOutput[1] = autoOutput[0];
	}

	// TODO: this may have some problems with the above adding... find a workaroun
	if(abs(autoOutput[0]) > 50) {
		autoOutput[0] = 0;
		autoOutput[1] = 0;
		drivetrainPID_forward.reset();
		drivetrainPID_straight.reset();
		drivetrainPID_turn.reset();
	}

	return autoOutput;

}



