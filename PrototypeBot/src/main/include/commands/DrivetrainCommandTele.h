#pragma once

#include "subsystems/Drivetrain.h"
#include "OI.h"
#include "RobotMap.h"
#include "frc/WPILib.h"
#include <frc/commands/Command.h>
#include "../Calculations/DrivetrainCalculations.h"

class DrivetrainCommandTele : public frc::Command {

public:
    DrivetrainCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    double output[3];
    DrivetrainCalculations* calculations;
};