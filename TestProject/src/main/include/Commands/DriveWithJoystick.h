#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include <Subsystems/Drivetrain.h> 
#include "OI.h"

class DriveWithJoystick : public Command {

public:
    DriveWithJoystick();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();    
};

#endif