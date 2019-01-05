#pragma once

#include "../Utilities/PIDControl.h"
#include <cmath>
#include <Commands/Subsystem.h>

class Drivetrain : public frc::Subsystem { 
public:

    bool InDeadBand(double joyValL, double joyValR);
    double* CalculateNextOutput(double joyValL, double joyValR, bool shifter);
    double outputs[3];
	Drivetrain();
    
    
};