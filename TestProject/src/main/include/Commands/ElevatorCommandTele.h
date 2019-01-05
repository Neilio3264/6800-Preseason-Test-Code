#ifndef ElevatorCommandTele_H
#define ElevatorCommandTele_H

#include "Subsystems/Elevator.h"
#include "../Robot.h"
#include "OI.h"
#include <VictorSP.h>
#include "RobotMap.h"
#include <Commands/Command.h>

class ElevatorCommandTele : public frc::Command {

public:
    ElevatorCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    VictorSP* liftA;
    VictorSP* liftB;

    Encoder* encoderElevator;
    
    double output;
};

#endif