#include "../../include/Subsystems/Intake.h"


Intake::Intake() : Subsystem("Intake") {
    angleSetpoint = MANUAL_MODE;
}

double *Intake::CalculateNextOutput(double leftTrig, double rightTrig, bool bumper, double rightStick, bool set1, bool set2) {
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
    if (!InDeadBand(rightStick)) {
        output[2] = rightStick;
    } else {
        UpdateAngleSetpoint(set1, set2)
        switch (angleSetpoint) {
            case MANUAL_MODE:
                output[2] = 0;
                break;
            default:
                output[2] = CalculateNextOutputAuto(currEncoder, angleSetpoint);
        }
    }

    return output;
}

double Intake::CalculateNextOutputAuto(double currEncoder, int angleSetpoint) {

    if(abs(currEncoder - angleSetpoint) < .02) { return 0;}

    switch (angleSetpoint) {
        case UP:
            if(currEncoder < .5) { return .5;}
            else {return -.5;} // TODO: Get a real encoder value here
            break;
        case DOWN:
            if(currEncoder < .2) { return .5;}
            else {return -.5;} // TODO: Get a real encoder value here
            break;
    }

}

void Intake::UpdateAngleSetpoint(bool set1, bool set2) {
    if(set1) { angleSetpoint = UP; }
    if(set2) { angleSetpoint = DOWN; }
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