/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <XboxController.h>
#include <LiveWindow/LiveWindow.h>
#include <VictorSP.h>
#include <Spark.h>
#include <Timer.h>
#include <GenericHID.h>
#include <cmath>

class Robot : public frc::IterativeRobot {

public:
	Robot() {
		m_robotDrive.SetExpiration(0.1);
		intake_right.SetExpiration(0.1);
		intake_left.SetExpiration(0.1);
		liftMotorA.SetExpiration(0.1);
		liftMotorB.SetExpiration(0.1);

		m_timer.Start();
	}

	void AutonomousInit() override {
		m_timer.Reset();
		m_timer.Start();
	}

	void AutonomousPeriodic() override {
		// Drive for 2 seconds
		if (m_timer.Get() < 4.0) {
			// Drive forwards half speed
			m_robotDrive.ArcadeDrive(-0.5, 0.0);
		} else {
			// Stop robot
			m_robotDrive.ArcadeDrive(0.0, 0.0);
		}
	}

	void TeleopInit() override {}

	void TeleopPeriodic() override {
		// Drive with arcade style (use right stick)
		m_robotDrive.TankDrive(-m_stick_left.GetY(), -m_stick_right.GetY(), false);

		if (gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) == 0) {
			intake_right.Set(gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand));
			intake_left.Set(gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand));
		}

		if (gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) == 0) {
			intake_right.Set(-gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand));
			intake_left.Set(-gamepad.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand));
		}

		if (gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand) < -0.01) {
			liftMotorA.Set(-0.2);
			liftMotorB.Set(-0.2);
		}
		else if(gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand) > 0.01) {
			liftMotorA.Set(0.6);
			liftMotorB.Set(0.6);
		}
		else {
			liftMotorA.Set(0.08);
			liftMotorB.Set(0.08);
		}

	}

	void TestPeriodic() override {}

private:
	// Robot drive system
	frc::VictorSP m_left{3};
	frc::VictorSP m_right{4};
	frc::VictorSP liftMotorA{8};
	frc::VictorSP liftMotorB{9};
	frc::Spark intake_right{0};
	frc::Spark intake_left{1};
	frc::DifferentialDrive m_robotDrive{m_left, m_right};

	frc::Joystick m_stick_left{1};
	frc::Joystick m_stick_right{2};
	frc::XboxController gamepad{0};
	frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
	frc::Timer m_timer;
};

START_ROBOT_CLASS(Robot)
