/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

OI::OI() {
  // Process operator interface input here.
  leftJoyDrive = new Joystick(1);
  rightJoyDrive = new Joystick(2);

  gamepad = new XboxController(0);

  pedal = new SendableBase(3);

}