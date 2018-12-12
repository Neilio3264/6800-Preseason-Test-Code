#include "PIDControl.h"
#include <iostream>

PIDControl::PIDControl() {
    PIDControl(0, 0, 0, 0, 0);
}

PIDControl::PIDControl(double p, double i, double d, double setpoint, double acc) {
    _kp = p;
    _ki = i;
    _kd = d;
    _setpoint = setpoint;

    _currError = 0;
    _prevError = 0;
    _integral = 0;
    
    _time = 0;
    
}

void PIDControl::reset() {
    _time = 0;
    _integral = 0;
}

void PIDControl::setSetpoint(double setpoint) {
    _setpoint = setpoint;
}

void PIDControl::setkP(double p) {
    _kp = p;
}

void PIDControl::setkI(double i) {
    _ki = i;
}

void PIDControl::setkD(double d) {
    _kd = d;
}

double PIDControl::getkP() {
    return _kp;
}

double PIDControl::getkI() {
    return _ki;
}

double PIDControl::getkD() {
    return _kd;
}


double PIDControl::PID_Loop(double setpoint, double p, double i, double d, double measuredValue, double acc, double dt) {

    if(abs(setpoint - measuredValue) <= acc) {
        return -100;
    }

    _prevError = _currError;

    _currError = setpoint - measuredValue;

    _integral += dt * _currError;

    double output = (_currError * (1/setpoint) * p) + (_integral * i) + (((_currError - _prevError) / dt) * d);

    return output + .08;

}

double PIDControl::P_Loop(double setpoint, double p, double measuredValue, double acc, double dt) {

    return PID_Loop(setpoint, p, 0, 0, measuredValue, acc, dt);

}

double PIDControl::PI_Loop(double setpoint, double p, double i, double measuredValue, double acc, double dt) {

    return PID_Loop(setpoint, p, i, 0, measuredValue, acc, dt);

}

double PIDControl::PD_Loop(double setpoint, double p, double d, double measuredValue, double acc, double dt) {

    return PID_Loop(setpoint, p, 0, d, measuredValue, acc, dt);

}