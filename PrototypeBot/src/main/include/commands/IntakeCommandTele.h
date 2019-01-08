#pragma once

#include "subsystems/Intake.h"
#include "../Robot.h"
#include "OI.h"
// #include "Phoenix.h"
// #include <Spark.h>
#include "RobotMap.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h"
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

    frc::Spark* intakeA;
    frc::Spark* intakeB;
    WPI_TalonSRX* angle;
    frc::Solenoid* solenoid;

    frc::Encoder* encoderIntake;

    double output[3];    
};