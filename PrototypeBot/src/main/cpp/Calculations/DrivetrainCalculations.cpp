#include "../../include/Calculations/DrivetrainCalculations.h"

DrivetrainCalculations::DrivetrainCalculations() {
    double outputs[3] = {0, 0, 0};
}

double* DrivetrainCalculations::CalculateNextOutput(double joyValL, double joyValR, bool shifter) {
    if (InDeadBand(joyValL, joyValR)) {
        outputs[0] = 0;
        outputs[1] = 0;
        outputs[2] = 0;
    } else {
        outputs[0] = -joyValL;
        outputs[1] = -joyValR;
        outputs[2] = shifter ? 1 : 0;
    }

    return outputs;

}

bool DrivetrainCalculations::InDeadBand(double joyValL, double joyValR) {
    if (abs(joyValL) < .05 && abs(joyValR) < .05 ) {
        return true;
    }
    return false;
} 