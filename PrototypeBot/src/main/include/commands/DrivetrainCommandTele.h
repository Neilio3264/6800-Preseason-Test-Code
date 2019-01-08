#pragma once

#include "subsystems/Drivetrain.h"
#include "../Robot.h"
#include "OI.h"
#include "RobotMap.h"
#include "frc/WPILib.h"
#include <frc/commands/Command.h>

class DrivetrainCommandTele : public frc::Command {

public:
    DrivetrainCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    frc::VictorSP* motorLeft;
    frc::VictorSP* motorRight;


    double output[3];    
};