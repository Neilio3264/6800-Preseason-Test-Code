#include "Calculations/DrivetrainCalculations.h"

DrivetrainCalculations::DrivetrainCalculations() {}

void DrivetrainCalculations::CalculateNextOutput(double*outputs, unsigned int size, double joyValL, double joyValR, bool shifter) {

    if (size < 3)
        return;
    
    if (InDeadBand(joyValL, joyValR)) {
        outputs[0] = 0;
        outputs[1] = 0;
        outputs[2] = 0;
    } else {
        outputs[0] = joyValL;
        outputs[1] = joyValR;
        outputs[2] = shifter ? 1 : 0;
    }

    // outputs[0] = 0;
    // outputs[1] = 0;
    // outputs[2] = 0;

}

bool DrivetrainCalculations::InDeadBand(double joyValL, double joyValR) {
    if (abs(joyValL) < .05 && abs(joyValR) < .05 ) {
        return true;
    }
    return false;
} 