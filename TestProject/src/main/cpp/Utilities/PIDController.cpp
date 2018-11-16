#include <cmath>
#include "../../include/Utilities/PIDController.h"
#include <Timer.h>



PIDController::PIDController(double p, double i, double d, double setpoint, double startValue, double acc){
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

void PIDController::setKp(double p) {
    kp = p;
}

void PIDController::setKi(double i) {
    ki = i;
}

void PIDController::setKd(double d) {
    kd = d;
}

double PIDController::getKp() {
    return kp;
}

double PIDController::getKi() {
    return ki;
}

double PIDController::getKd() {
    return kd;
}


double PIDController::PID_Loop(double setpoint, double p, double i, double d, double measuredValue) {


    double _timeDiff = _timer.Get() - _lastTime;
    double totalError = setpoint - startValue;
    _prevError = _currError;
    _currError = setpoint - measuredValue;
    _integral += timeDiff * _currError;

    output = _currError * setpoint + (_integral) + (_currError - _prevError) / (_timeDiff);

    _lastTime = timer.Get();

    return output;

}

double PIDController::P_Loop(double setpoint, double p, double measuredValue) {

    return PID_Loop(setpoint, p, 0, 0, measuredValue);

}

double PIDController::PI_Loop(double setpoint, double p, double i, double measuredValue) {

    return PID_Loop(setpoint, p, i, 0, measuredValue);

}

double PIDController::PD_Loop(double setpoint, double p, double d, double measuredValue) {

    return PID_Loop(setpoint, p, 0, d, measuredValue);

}




