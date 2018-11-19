#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "VictorSP.h"
#include "RobotMap.h"

class Elevator : public Subsystem {
private:
 
	VictorSP *liftMotorA;
    VictorSP *liftMotorB;


public:
	Elevator();

	void InitDefaultCommand();
    void Start(double power);
    void Stop();

};

#endif  