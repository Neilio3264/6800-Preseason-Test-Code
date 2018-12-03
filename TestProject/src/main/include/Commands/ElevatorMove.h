#ifndef ElevatorMove_H
#define ElevatorMove_H

#include <Subsystems/Elevator.h> 
#include "OI.h"
#include "WPILib.h"

class ElevatorMove : public Command {

private:
    VictorSP liftMotorA;
    VictorSP liftMotorB;
    Encoder liftEncoder;

public:

    ElevatorMove();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif