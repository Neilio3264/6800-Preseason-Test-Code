#pragma once

#include "subsystems/Elevator.h"
#include "../Robot.h"
#include "OI.h"
#include "frc/WPILib.h"
#include "RobotMap.h"
#include <frc/commands/Command.h>

class ElevatorCommandTele : public frc::Command {
    
public:
    ElevatorCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    frc::VictorSP* liftA;
    frc::VictorSP* liftB;

    frc::Encoder *encoderElevator;
    
    double output;
};