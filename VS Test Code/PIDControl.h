#ifndef PIDControl_H
#define PIDControl_H

#include <cmath>

class PIDControl {

private:
    double _kp;
    double _ki;
    double _kd;
    double _setpoint;
    
    double _currError;
    double _prevError;
    double _integral;

    double _time;

public:

    PIDControl();
    PIDControl(double p, double i, double d, double setpoint, double acc);

    void setkP(double kp);
    double getkP();
    void setkI(double ki);
    double getkI();
    void setkD(double kd);
    double getkD();
    void setSetpoint(double setpoint);
    void reset();

    double P_Loop(double error, double p, double measuredValue, double acc, double dt);
    double PI_Loop(double error, double p, double i, double measuredValue, double acc, double dt);
    double PD_Loop(double error, double p, double d, double measuredValue, double acc, double dt);
    double PID_Loop(double setpoint, double p, double i, double d, double measuredValue, double acc, double dt);     
};

#endif