/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() {
  // Process operator interface input here.
  leftJoyDrive = new frc::Joystick(1);
  rightJoyDrive = new frc::Joystick(2);

  gamepad = new frc::XboxController(0);

  //pedal = new Button(3);

}

frc::Joystick* OI::getLeftJoyDrive() {
  return leftJoyDrive;
}

frc::Joystick* OI::getRightJoyDrive() {
  return rightJoyDrive;
}

frc::XboxController* OI::getGamepad() {
  return gamepad;
}