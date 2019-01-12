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
#include "../commands/IntakeCommandTele.h"
// #include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/Spark.h>
#include <frc/Encoder.h>
#include <frc/Solenoid.h>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

using namespace frc;

class Intake : public Subsystem {
public:
   Intake();
   void InitDefaultCommand();

   void setIntakeSpeed (double power);
   // void setAngleSpeed(double power);
   void setSolenoid(double output);
private:
   Spark intakeA{0};
   Spark intakeB{1};
   // ctre::phoenix::motorcontrol::can::WPI_TalonSRX angle{0};
   Solenoid solenoid{2}; // TODO: Put in correct port
   Encoder encoderIntake{1, 2, false, Encoder::k1X};
};
