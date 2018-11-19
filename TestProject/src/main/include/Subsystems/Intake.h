#ifndef Intake_H
#define Intake_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "Spark.h"
#include "Talon.h"
#include "RobotMap.h"

class Intake : public Subsystem {
private:

    Spark *_intakeA;
    Spark *_intakeB;
    Talon *_angle;
    Solenoid *_clamp;


public:
	Intake();
    void Clamp(bool isClamped);
    void SetIntakeSpeedIn(double power);
    void SetIntakeSpeedOut(double power);
    void SetAngle(double power);

};

#endif  