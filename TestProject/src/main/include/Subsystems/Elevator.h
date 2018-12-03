#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "../Utilities/PIDControl.h"
#include <cmath>

class Elevator : public Subsystem {
private:

    static constexpr int MANUAL_MODE = 0;
    static constexpr int LOW_SETPOINT = 1;
    static constexpr int MEDIUM_SETPOINT = 2;
    static constexpr int HIGH_SETPOINT = 3;
    double p_val;
    double i_val;
    double d_val;
    double accuracy;
    double dt;
    int targetSetPoint;
    PIDControl elevatorPID;

    bool InDeadBand(double joyVal);
    void UpdateTargetSetpoint(bool set1, bool set2, bool set3);
    double CalculateNextAutoOutput(int targetSetPoint, double currEncoder, double dt);

public:
	Elevator();
    
    double CalculateNextOutput(bool set1, bool set2, bool set3, double joyVal, double encoder); // TODO: Research what encoder returns

};

#endif