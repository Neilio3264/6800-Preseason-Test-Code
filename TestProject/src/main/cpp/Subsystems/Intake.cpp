#include "../../include/Subsystems/Intake.h"


Intake::Intake() : Subsystem("Intake") {}

double *Intake::CalculateNextOutput(double leftTrig, double rightTrig, bool bumper, double rightStick) {
    if(!InDeadBand(leftTrig, rightTrig)) {
        if(leftTrig > .05) {
            output[0] = -leftTrig;
        } else {
            output[0] = rightTrig;
        }
    } else {
        output[0] = 0;
    }

    output[1] = bumper ? 1 : 0;
    output[2] = !InDeadBand(rightStick) ? rightStick : 0;

    return output;

}

bool InDeadBand(double rightStick) {
    return rightStick < .05;
}

bool InDeadBand(double leftVal, double rightVal) {
    if(leftVal > .05 && rightVal > .05) {
        return true;
    }

    if(leftVal < .05 && rightVal < .05) {
        return true;
    }

    return false;
}


