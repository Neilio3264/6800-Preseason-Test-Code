#pragma once

#include "subsystems/Elevator.h"
#include "Calculations/ElevatorCalculations.h"
#include <frc/commands/Command.h>

class ElevatorCommandTele : public frc::Command {
    
public:
    ElevatorCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

private:
    ElevatorCalculations* calculationsElevator;
};