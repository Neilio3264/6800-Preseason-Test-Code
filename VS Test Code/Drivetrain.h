#ifndef Drivetrain_H
#define Drivetrain_H

using namespace std;

#include "PIDControl.h"
#include <cmath>

class Drivetrain{
public:

	Drivetrain();
    bool InDeadBand(double, double);
    void CalculateNextOutput(double*, unsigned int, double, double, bool);
    
};

#endif  