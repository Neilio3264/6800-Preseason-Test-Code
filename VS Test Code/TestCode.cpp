#include <iostream>
#include <cmath>
#include <ctime>

#include "PIDControl.h"
#include "Elevator.h"
#include "Drivetrain.h"

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
        /*
        Testing Drivetrain merge
        Again aodsihf;adjkslfhasd;hflkasd
    clock_t t;
    int f;
    t = clock();
    cout << "Calculating..." << "\n"; akdshfjl
    f = frequency_of_primes (99999);
    cout << "The number of primes lower than 100,000 is: " << f << "\n";
    t = clock() - t;
    int click = round((float)t / 1000);
    printf ("It took %d clicks to complete (%f millisenconds).\n", click, ((float)t/CLOCKS_PER_SEC)*1000);
    return 0;
        */

    // bool set1 = false;
    // bool set2 = false;
    // bool set3 = false;
    // double joyVal = 1;
    // double encoder = 0;

    // double output = 0;

    // Elevator elevator = *new Elevator();

    // // cout << elevator.CalculateNextOutput(set1, set2, set3, joyVal, encoder) << "\n"; 

    // while (output != .08) {

    //     output = elevator.CalculateNextOutput(set1, set2, set3, joyVal, encoder);
    //     cout << output << '\n';
    //     encoder = encoder + .01;

    //     set1 = false;
    //     set2 = false;
    //     set3 = false;
    // }

    // cout << elevator.CalculateNextOutput(set1, set2, set3, joyVal, encoder) << '\n';

    // return 0;

    double joyValL = 0;
    double joyValR = 0;


    Elevator elevator = *new Elevator();
    Drivetrain drivetrain = *new Drivetrain();

    while(true) {
        cout << drivetrain.CalculateNextOutput(joyValL, joyValR, false)[0] << ", " << &drivetrain.CalculateNextOutput(joyValL, joyValR, false)[1] << '\n';
        // cout << elevator.CalculateNextOutput(false, false, false, 1, 0) << '\n';
    }

    return 0;
}