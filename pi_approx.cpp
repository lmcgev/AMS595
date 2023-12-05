//Code for question 1 on HW
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

//structure that stores the results from the function, with two values, approx and error, both floats
struct PiResults {
    float approx;
    float error;
} ;

//function that estimates pi
PiResults pi_approx (int N) {
    /*Estimates pi using the trapezoid rule to evaluate int(0,1)[sqrt(1-x^2)]dx = pi/4

    Calculates delta x using users integer input N (the interval)

    Finds the error as abs(approximate - actual). Both the approximation and error stored in a structure called PiResults which is returned.
    */

    float dx = 1.0 / N; //takes delta using [0,1] and N

    //performs the summation in the trapezoid rule
    float sum = 0.0;
    for (int i=1; i < N; i++) {
        sum += 2 * sqrt(1 - pow((i*dx), 2));
    }

    PiResults results;
    results.approx = 4 * ((sum + 1) * (dx/2)); //approximate pi is the summation + start and end point time delta over 2 times 4
    results.error = abs(results.approx - M_PI); //stores error as approximate - M_Pi from cmath
    return results; //returns the structure 
}
