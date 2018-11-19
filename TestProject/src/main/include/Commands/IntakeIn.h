#ifndef IntakeIn_H
#define IntakeIn_H

#include <Subsystems/Intake.h> 
#include "OI.h"

class IntakeIn : public Command {

public:
    IntakeIn();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif