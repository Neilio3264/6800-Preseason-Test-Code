/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

class Intake : public frc::Subsystem {
 public:
    Intake();
    void InitDefaultCommand() override;

    double* CalculateNextOutput(double leftTrig, double rightTrig, bool bumper, double rightStick, bool set1, bool set2, double currEncoder);
    double CalculateNextOutputAuto(double currEncoder, int angleSetpoint);
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
    static constexpr int MANUAL_MODE = 0;
    static constexpr int UP = 1;
    static constexpr int DOWN = 2;

    static constexpr int CLAMP = 1;
    static constexpr int UNCLAMP = 2;

    static constexpr int INTAKE = 1;
    static constexpr int EJECT = 2;

    int angleSetpoint;
    int clampState;
    int intakeState;

    double output[3];

    // 0 - intake wheels
    // 1 - clamp
    // 2 - angle

    void UpdateAngleSetpoint(bool set1, bool set2);
    bool InDeadBand(double leftTrig, double rightTrig);
    bool InDeadBand(double rightStick);
};
