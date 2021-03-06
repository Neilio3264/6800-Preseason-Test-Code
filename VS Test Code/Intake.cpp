#include "Intake.h"

Intake::Intake() {
    angleSetpoint = MANUAL_MODE;
    intakeState = MANUAL_MODE;
    clampState = MANUAL_MODE;

    double output[3] = {0.0, 0.0, 0.0};
}

void Intake::CalculateNextOutput(double* output, unsigned int size, double leftTrig, double rightTrig, bool bumper, double rightStick, bool set1, bool set2, double currEncoder) {

    if(size < 3) {
        return;
    }

    if(!InDeadBand(leftTrig, rightTrig)) {
        if(leftTrig > .05) {
            output[0] = -leftTrig;
            intakeState = EJECT;
        } else {
            output[0] = rightTrig;
            intakeState = INTAKE;
        }
    } else {
        output[0] = 0;
    }

    if (bumper) {
        output[1] = 1;
        clampState = CLAMP;
    } else {
        output[1] = 0;
        clampState = UNCLAMP;
    }

    if (!InDeadBand(rightStick)) {
        output[2] = rightStick;
    } else {
        UpdateAngleSetpoint(set1, set2);
        switch (angleSetpoint) {
            case MANUAL_MODE:
                output[2] = 0;
                break;
            default:
                output[2] = CalculateNextOutputAuto(currEncoder, angleSetpoint);
        }
    }
}

double Intake::CalculateNextOutputAuto(double currEncoder, int angleSetpoint) {

    if( abs(currEncoder - angleSetpoint) < .02) { return 0;}

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
    if (set1) { angleSetpoint = UP; }
    if (set2) { angleSetpoint = DOWN; }
}

bool Intake::InDeadBand(double rightStick) {
    return rightStick < .05;
}

bool Intake::InDeadBand(double leftVal, double rightVal) {
    if(leftVal > .05 && rightVal > .05) {
        return true;
    }

    if(leftVal < .05 && rightVal < .05) {
        return true;
    }

    return false;
}