/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../utilities/PIDControl.h"
#include <cmath>
#include "RobotMap.h"
#include "frc/WPILib.h"
#include "OI.h"
#include <frc/commands/Command.h>
#include "../commands/IntakeCommandTele.h"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h"

class Intake : public frc::Subsystem {
public:
   Intake();
   void InitDefaultCommand() override;
    
   frc::Spark* intakeA;
   frc::Spark* intakeB;
   WPI_TalonSRX* angle;
   frc::Solenoid* solenoid;

   frc::Encoder* encoderIntake;

   void setIntakeSpeed (double power);
   void setAngleSpeed(double power);
   void setSolenoid(double output);
};
