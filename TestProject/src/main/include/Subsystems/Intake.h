#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>

class Intake : public Subsystem {
private:
    static double output[3];
    bool InDeadBand(double leftTrig, double rightTrig);
    bool InDeadBand(double rightStick);

public:
    Intake();
    double * CalculateNextOutput();


};

#endif  