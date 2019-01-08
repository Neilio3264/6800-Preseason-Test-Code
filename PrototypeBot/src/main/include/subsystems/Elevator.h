/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../utilities/PIDControl.h"
#include "../utilities/Constants.h"
#include <cmath>

class Elevator : public frc::Subsystem {
 public:
    Elevator();
    void InitDefaultCommand() override;

    double p_val;
    double i_val;
    double d_val;
    double accuracy;
    double dt;
    int targetSetPoint;
    PIDControl *elevatorPID;

    bool InDeadBand(double joyVal);
    void UpdateTargetSetpoint(bool set1, bool set2, bool set3);
    double CalculateNextAutoOutput(int targetSetPoint, double currEncoder, double dt);
    
    double CalculateNextOutput(bool set1, bool set2, bool set3, double joyVal, double encoder); // TODO: Research what encoder returns
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
