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
#include "../commands/DrivetrainCommandTele.h"
#include <frc/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>

class Drivetrain : public frc::Subsystem {
  public:
    Drivetrain();
  
    void InitDefaultCommand();

    void TankDrive(double leftPower, double rightPower);  
  private:

    frc::VictorSP motorLeft{3};
    frc::VictorSP motorRight{4};

    frc::DifferentialDrive _robotDrive{motorLeft, motorRight};

};
