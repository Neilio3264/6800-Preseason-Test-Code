/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "OI.h"
#include "RobotMap.h"
#include "commands/ElevatorCommandTele.h"
#include <frc/VictorSP.h>
#include <frc/Encoder.h>

class Elevator : public frc::Subsystem {
 public:
    Elevator();
    void InitDefaultCommand();
    void setLiftMotors(double power);
    double getEncoder();
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
   frc::VictorSP liftA{8};
   frc::VictorSP liftB{9};
   frc::Encoder encoderElevator{5, 6, false, frc::Encoder::k1X};
};
