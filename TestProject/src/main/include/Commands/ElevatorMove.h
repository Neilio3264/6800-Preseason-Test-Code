#ifndef ElevatorMove.H
#define ElevatorMove.H

#include <Subsystems/Elevator.h> 
#include "OI.h"

class ElevatorMove : public Command {

public:

    ElevatorMove();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif