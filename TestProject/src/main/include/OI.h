/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include <XboxController.h>
#include <Joystick.h>
#include <Buttons/Button.h>

class OI {
 private:
  Joystick* leftJoyDrive;
  Joystick* rightJoyDrive;

  XboxController* gamepad;
 public:
  Joystick* getLeftJoyDrive();
  Joystick* getRightJoyDrive();
  XboxController* getGamepad();

  //Button *pedal;
  OI();
};
#endif