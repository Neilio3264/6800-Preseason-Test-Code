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

class Drivetrain : public frc::Subsystem {
 public:
    Drivetrain();
    void InitDefaultCommand() override;

    bool InDeadBand(double joyValL, double joyValR);
    double* CalculateNextOutput(double joyValL, double joyValR, bool shifter);
    double outputs[3];
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
