#include <iostream>
#include <cmath>
#include <ctime>

#include "PIDControl.h"
#include "Elevator.h"
#include "Drivetrain.h"
#include "Intake.h"

using namespace std;

/*
int frequency_of_primes (int n) {
  int i,j;
  int freq=n-1;
  for (i=2; i<=n; ++i) for (j=sqrt(i);j>1;--j) if (i%j==0) {--freq; break;}
  return freq;
}
*/

int main ()
{
    // ============ INTAKE TEST =========================

    Intake intake;
    

    // ============ ELEVATOR TEST =======================
    // bool set1 = false;
    // bool set2 = false;
    // bool set3 = false;
    // double joyVal = 1;
    // double encoder = 0;

    // double output = 0;

    // Elevator elevator;

    // while(true) {

    //     output = elevator.CalculateNextOutput(set1, set2, set3, joyVal, encoder);
    //     cout << output << '\n';
    //     encoder = encoder + .01;

    //     set1 = false;
    //     set2 = false;
    //     set3 = false;
    // }

    // cout << elevator.CalculateNextOutput(set1, set2, set3, joyVal, encoder) << '\n';

    // return 0;

    // ============ DRIVETRAIN TEST =======================
    // double joyValL = .5;
    // double joyValR = .6;

    // Drivetrain drivetrain;
    // double drivetrainOutputs[3]; 

    // while(true) {
    //     drivetrain.CalculateNextOutput(drivetrainOutputs, sizeof(drivetrainOutputs), joyValL, joyValR, false);
    //     cout << drivetrainOutputs[0] << ", " << drivetrainOutputs[1] << '\n';
    // }


    return 0;
}