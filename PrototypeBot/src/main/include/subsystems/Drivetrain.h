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
#include <frc/WPILib.h>
#include "OI.h"
#include "../commands/DrivetrainCommandTele.h"
#include <frc/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>

class Drivetrain : public frc::Subsystem {
 public:
   Drivetrain();
   
   void InitDefaultCommand() override;

   void TankDrive(double leftPower, double rightPower);
 private:
   frc::VictorSP motorLeft{DRIVE_LEFTMOTOR};
   frc::VictorSP motorRight{DRIVE_RIGHTMOTOR};

   frc::DifferentialDrive _robotDrive{motorLeft, motorRight};
};
