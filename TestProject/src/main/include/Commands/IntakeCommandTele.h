#ifndef IntakeCommandTele_H
#define IntakeCommandTele_H

#include "Subsystems/Intake.h"
#include "../Robot.h"
#include "OI.h"
#include "ctre/Phoenix.h"
#include <Spark.h>
#include "RobotMap.h"
#include "WPILib.h"
#include <GenericHID.h>
#include <Commands/Command.h>

class IntakeCommandTele : public frc::Command {

public:
    IntakeCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    Spark* intakeA;
    Spark* intakeB;
    TalonSRX* angle;
    Solenoid* solenoid;

    Encoder* encoderIntake;

    double output[3];    
};

#endif