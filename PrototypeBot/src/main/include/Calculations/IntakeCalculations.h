#ifndef IntakeCalculations_H
#define IntakeCalculations_H

using namespace std;

#include <cmath>

class IntakeCalculations {
 public:
    IntakeCalculations();

    void CalculateNextOutput(double*, unsigned int, double leftTrig, double rightTrig, bool bumper, double rightStick, bool set1, bool set2, double currEncoder);
    double CalculateNextOutputAuto(double currEncoder, int angleSetpoint);
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
    static constexpr int MANUAL_MODE = 0;
    static constexpr int UP = 1;
    static constexpr int DOWN = 2;

    static constexpr int CLAMP = 1;
    static constexpr int UNCLAMP = 2;

    static constexpr int INTAKE = 1;
    static constexpr int EJECT = 2;

    int angleSetpoint;
    int clampState;
    int intakeState;

    // 0 - intake wheels
    // 1 - clamp
    // 2 - angle

    void UpdateAngleSetpoint(bool set1, bool set2);
    bool InDeadBand(double leftTrig, double rightTrig);
    bool InDeadBand(double rightStick);
};

#endif