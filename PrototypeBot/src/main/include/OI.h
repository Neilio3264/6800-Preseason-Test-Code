/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef OI_H
#define OI_H
#include "frc/WPILib.h"
#include "frc/XboxController.h"
#include "frc/Joystick.h"
#include "frc/buttons/Button.h"

class OI {
 private:
  frc::Joystick* leftJoyDrive;
  frc::Joystick* rightJoyDrive;

  frc::XboxController* gamepad;
 public:
  frc::Joystick* getLeftJoyDrive();
  frc::Joystick* getRightJoyDrive();
  frc::XboxController* getGamepad();

  //Button *pedal;
  OI();
};
#endif