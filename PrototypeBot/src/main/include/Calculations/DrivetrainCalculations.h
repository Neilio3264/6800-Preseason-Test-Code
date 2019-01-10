#pragma once

#include "../utilities/PIDControl.h"
#include <cmath>

class DrivetrainCalculations {

public:
    DrivetrainCalculations();

    bool InDeadBand(double joyValL, double joyValR);
    double* CalculateNextOutput(double joyValL, double joyValR, bool shifter);
    

private:
    double outputs[3];
};