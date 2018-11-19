#ifndef IntakeOut_H
#define IntakeOut_H

#include <Subsystems/Intake.h> 
#include "OI.h"

class IntakeOut : public Command {

public:
    IntakeOut();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif