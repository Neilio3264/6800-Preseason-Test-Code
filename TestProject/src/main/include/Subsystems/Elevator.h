#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "../Utilities/PIDControl.h"
#include "RobotMap.h"
#include <cmath>
#include <WPILib.h>

class Elevator : public Subsystem {
private:

    double p_val;
    double i_val;
    double d_val;
    double accuracy;
    int targetSetPoint;
    PIDControl elevatorPID;

    bool InDeadBand(double joyVal);
    void UpdateTargetSetpoint(bool set1, bool set2, bool set3);
    double CalculateNextAutoOutput(int targetSetPoint, double currEncoder);

public:
	Elevator();
    
    double CalculateNextOutput(bool set1, bool set2, bool set3, double joyVal, double encoder); // TODO: Research what encoder returns

};

#endif  