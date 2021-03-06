#ifndef Elevator_H
#define Elevator_H

using namespace std;

#include "PIDControl.h"
#include <cmath>

class Elevator {
public:

    double p_val;
    double i_val;
    double d_val;
    double accuracy;
    double dt;
    int targetSetPoint;
    PIDControl *elevatorPID;

    bool InDeadBand(double joyVal);
    void UpdateTargetSetpoint(bool set1, bool set2, bool set3);
    double CalculateNextAutoOutput(int targetSetPoint, double currEncoder, double dt);

	Elevator();
    
    double CalculateNextOutput(bool set1, bool set2, bool set3, double joyVal, double encoder); // TODO: Research what encoder returns

};

#endif  