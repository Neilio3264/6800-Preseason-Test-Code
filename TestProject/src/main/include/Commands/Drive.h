#ifndef Drive_H
#define Drive_H

#include <Subsystems/Drivetrain.h> 
#include "../Utilities/PIDControl.h"

class Drive : public Command {

public:
    PIDControl pid;
    Drive(double p, double i, double d, double setpoint, double startValue, double acc);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif