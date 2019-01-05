#include "Subsystems/Elevator.h"

double ELEVATOR_IDLE_MOTOR_POWER = 0.08;

Elevator::Elevator() : frc::Subsystem("Elevator") {
    targetSetPoint = 0;
    p_val = .5;
    i_val = .2;
    d_val = .1;
    accuracy = .01;
    elevatorPID = new PIDControl(p_val, i_val, d_val, 0, 0);
    dt = 0.02;
}

double Elevator::CalculateNextOutput(bool set1, bool set2, bool set3, double joyVal, double encoder) {

    if(targetSetPoint == 1 && abs(encoder - .15) <= .01) { targetSetPoint = 0; }
    if(targetSetPoint == 2 && abs(encoder - .4) <= .01) { targetSetPoint = 0; }
    if(targetSetPoint == 3 && abs(encoder - .6) <= .01) { targetSetPoint = 0; }

    if (!InDeadBand(joyVal)) {
        // For sure in manual mode, set targetSetPoint to 0;
        // Return joyVal reading
        targetSetPoint = 0;
        return joyVal;
    }
    else {
        UpdateTargetSetpoint(set1, set2, set3);
        
        if(targetSetPoint == 0) { 
            return ELEVATOR_IDLE_MOTOR_POWER; 
        }

        return CalculateNextAutoOutput(targetSetPoint, encoder, dt);
    }
}

bool Elevator::InDeadBand(double joyVal) {
    return abs(joyVal) <= .05;
}

void Elevator::UpdateTargetSetpoint(bool set1, bool set2, bool set3) {

    if((set1 && !set2 && !set3) || (!set1 && set2 && !set3) || (!set1 && !set2 && set3)) {
        if(set1) { targetSetPoint = 1; }
        if(set2) { targetSetPoint = 2; }
        if(set3) { targetSetPoint = 3; }
    } else {
        targetSetPoint = 0;
    }
    
}

double Elevator::CalculateNextAutoOutput(int targetSetPoint, double currEncoder, double dt) {
    
    double targetEncoder;

    switch(targetSetPoint) {
        case 1: 
            targetEncoder = .15; //TODO: Update with real setpoint val
            break;
        case 2: 
            targetEncoder = .4; //TODO: Update with real setpoint val
            break;
        case 3: 
            targetEncoder = .6; //TODO: Update with real setpoint val
            break;
    }
    double output;

    // std::cout << targetEncoder << " " << p_val << " " << currEncoder << " " << accuracy << " " << dt << "\n";

    output = elevatorPID->PID_Loop(targetEncoder, p_val, 0, d_val, currEncoder, accuracy, dt);

    if(output == -100) {
        return ELEVATOR_IDLE_MOTOR_POWER;
        targetSetPoint = 0;
    }

    return output;
}