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
#include "../commands/IntakeCommandTele.h"
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/Spark.h>

class Intake : public frc::Subsystem {
public:
   Intake();
   void InitDefaultCommand() override;

   void setIntakeSpeed (double power);
   void setAngleSpeed(double power);
   void setSolenoid(double output);
private:
   frc::Spark intakeA{INTAKE_CUBE_MOTOR_A};
   frc::Spark intakeB{INTAKE_CUBE_MOTOR_B};
   ctre::phoenix::motorcontrol::can::WPI_TalonSRX* angle{0};
   frc::Solenoid* solenoid; // TODO: Put in correct port
   frc::Encoder* encoderIntake;
};
