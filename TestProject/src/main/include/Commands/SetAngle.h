#ifndef SetAngle_H
#define SetAngle_H

#include <Subsystems/Intake.h> 
#include "OI.h"

class SetAngle : public Command {

public:

    SetAngle();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif