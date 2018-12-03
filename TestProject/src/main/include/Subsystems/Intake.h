#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>

class Intake : public Subsystem {
private:
    static constexpr int MANUAL_MODE = 0;
    static constexpr int UP = 1;
    static constexpr int DOWN = 2;

    int angleSetpoint;
    static double output[3];
    void UpdateAngleSetpoint(bool set1, bool set2);
    bool InDeadBand(double leftTrig, double rightTrig);
    bool InDeadBand(double rightStick);

public:
    Intake();
    double* CalculateNextOutput(double leftTrig, double rightTrig, bool bumper, double rightStick, bool set1, bool set2);
    double CalculateNextOutputAuto(double currEncoder, int angleSetpoint);

};

#endif