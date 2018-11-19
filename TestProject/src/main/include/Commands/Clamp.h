#ifndef Clamp_H
#define Clamp_H

#include <Subsystems/Intake.h> 
#include "OI.h"

class Clamp : public Command {

public:
    Clamp();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif