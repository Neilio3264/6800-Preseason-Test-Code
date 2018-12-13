#ifndef Drivetrain_H
#define Drivetrain_H

#include "PIDControl.h"
#include <cmath>

class Drivetrain {
public:

    bool InDeadBand(double joyValL, double joyValR);
    double* CalculateNextOutput(double joyValL, double joyValR, bool shifter);
    static double outputs[3];
	Drivetrain();
    
    
};

#endif  