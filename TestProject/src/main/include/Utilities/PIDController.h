#ifndef PIDController_H
#define PIDController_H

#include <Timer.h>

class PIDController {

private:
    PIDController(double p, double i, double d, double setpoint, double startValue, double acc);
    double _kp;
    double _ki;
    double _kd;
    double _setpoint;
    double _startValue;
    
    double _currError;
    double _prevError;
    double _integral;

    Timer _timer;
    double _lastTime;


public:

    void setkP(double kp);
    double getkP();
    void setkI(double ki);
    double getkI();
    void setkD(double kd);
    double getkD();

    double P_Loop(double error, double p, double measuredValue);
    double PI_Loop(double error, double p, double i, double measuredValue);
    double PD_Loop(double error, double p, double d, double measuredValue);
    double PID_Loop(double setpoint, double p, double i, double d, double measuredValue);     
};

#endif

