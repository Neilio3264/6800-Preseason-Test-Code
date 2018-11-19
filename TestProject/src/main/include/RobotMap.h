/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

//Motor Controller IDs
constexpr int DRIVE_LEFTMOTOR   	= 3;
constexpr int DRIVE_RIGHTMOTOR	    = 4;

constexpr int LIFT_MOTOR_A 	    	= 8;
constexpr int LIFT_MOTOR_B   		= 9;

constexpr int SHIFTER               = 1; // NOTE: WRONG PORT (PROBABLY)

constexpr int CLAMPER               = 2; // NOTE: WRONG PORT (PROBABLY)

constexpr int INTAKE_CUBE_MOTOR_A 	= 0;
constexpr int INTAKE_CUBE_MOTOR_B   = 1; 
constexpr int INTAKE_ANGLE_MOTOR	= 12; // NOTE: WRONG PORT (PROBABLY)

#endif  // ROBOTMAP_H
