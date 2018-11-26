#include <cmath>
#include "../../include/Utilities/PIDControl.h"
#include <Timer.h>



PIDControl::PIDControl(double p, double i, double d, double setpoint, double startValue, double acc){
    _kp = p;
    _ki = i;
    _kd = d;
    _setpoint = setpoint;
    _startValue = startValue;

    _currError = 0;
    _prevError = 0;
    _integral = 0;
    
    _timer.Reset();
    _timer.Start();
    _lastTime = _timer.Get();
    
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


double PIDControl::PID_Loop(double setpoint, double p, double i, double d, double measuredValue) {


    double _timeDiff = _timer.Get() - _lastTime;
    double totalError = setpoint - _startValue;
    _prevError = _currError;
    _currError = setpoint - measuredValue;
    _integral += _timeDiff * _currError;

    double output = _currError * setpoint * p + (_integral) * i + (_currError - _prevError) / (_timeDiff) * d;

    _lastTime = _timer.Get();

    return output;

}

double PIDControl::P_Loop(double setpoint, double p, double measuredValue) {

    return PID_Loop(setpoint, p, 0, 0, measuredValue);

}

double PIDControl::PI_Loop(double setpoint, double p, double i, double measuredValue) {

    return PID_Loop(setpoint, p, i, 0, measuredValue);

}

double PIDControl::PD_Loop(double setpoint, double p, double d, double measuredValue) {

    return PID_Loop(setpoint, p, 0, d, measuredValue);

}




