#include "Drivetrain.h"
#include <iostream>

// Drivetrain::Drivetrain() {
// }

double* Drivetrain::CalculateNextOutput(double joyValL, double joyValR, bool shifter) {
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

    return outputs;

}

bool Drivetrain::InDeadBand(double joyValL, double joyValR) {
    if (abs(joyValL) < .05 && abs(joyValR) < .05 ) {
        return true;
    }
    return false;
} 