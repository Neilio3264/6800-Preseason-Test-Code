#pragma once

// #include <frc/WPILib.h>
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

    // double output[3];

private:
    DrivetrainCalculations* calculationsDrivetrain;

    double left, right;
};