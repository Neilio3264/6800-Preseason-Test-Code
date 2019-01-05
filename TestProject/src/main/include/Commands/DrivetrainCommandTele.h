#ifndef DrivetrainCommandTele_H
#define DrivetrainCommandTele_H

#include "Subsystems/Drivetrain.h"
#include "../Robot.h"
#include "OI.h"
#include <VictorSP.h>
#include "RobotMap.h"
#include "WPILib.h"
#include <Commands/Command.h>

class DrivetrainCommandTele : public frc::Command {

public:
    DrivetrainCommandTele();
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

    VictorSP* motorLeft;
    VictorSP* motorRight;


    double output[3];    
};

#endif