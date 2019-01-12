#pragma once

#include "subsystems/Intake.h"
#include "OI.h"
#include "Calculations/IntakeCalculations.h"
#include <frc/GenericHID.h>
#include <frc/commands/Command.h>

class IntakeCommandTele : public frc::Command {

public:
    IntakeCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

private:
    IntakeCalculations* calculationsIntake;
};