#ifndef DrivetrainCalculations_H
#define DrivetrainCalculations_H

using namespace std;

#include "../utilities/PIDControl.h"
#include <cmath>

class DrivetrainCalculations{
public:

	DrivetrainCalculations();
    bool InDeadBand(double, double);
    void CalculateNextOutput(double*, unsigned int, double, double, bool);
    
};

#endif  