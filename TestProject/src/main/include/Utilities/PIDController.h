#ifndef PIDController_H
#define PIDController_H

#include <Timer.h>

class PIDController {

private:
    PIDController(double p, double i, double d, double sp);
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

    void setKP(double kp);
    double getKP();
    void setKI(double ki);
    double getKI();
    void setKD(double kd);
    double getKD();

    double P_Loop(double error, double p, double measuredValue);
    double PI_Loop(double error, double p, double i, double measuredValue);
    double PD_Loop(double error, double p, double d, double measuredValue);
    double PID_Loop(double setpoint, double p, double i, double d, double measuredValue);     
};

#endif

