#ifndef Elevator_H
#define Elevator_H

#include <Commands/Subsystem.h>
#include "VictorSP.h"
#include "RobotMap.h"

class Elevator : public Subsystem {
private:
 
	


public:
	Elevator();

    VictorSP *liftMotorA;
    VictorSP *liftMotorB;

	void InitDefaultCommand();
    void Start(double power);
    void Stop();

};

#endif  