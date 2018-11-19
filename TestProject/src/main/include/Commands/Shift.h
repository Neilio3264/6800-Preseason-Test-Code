#ifndef Shift_H
#define Shift_H

#include <Subsystems/Drivetrain.h> 
#include "OI.h"

class Shift : public Command {

public:

    Shift();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif