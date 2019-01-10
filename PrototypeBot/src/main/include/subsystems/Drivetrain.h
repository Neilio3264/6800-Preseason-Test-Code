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
#include "../commands/DrivetrainCommandTele.h"

class Drivetrain : public frc::Subsystem {
 public:
   Drivetrain();
   
   void InitDefaultCommand() override;
   
   void setMotorLeft(double power);
   void setMotorRight(double power);
   
   frc::VictorSP* motorLeft;
   frc::VictorSP* motorRight;

 private:
   
};
