//Header File for HW2
//header guard that contains all the neccessary libraries and structures needed to run the other files
#ifndef _HW6_FUNCTIONS_H_
#define _HW6_FUNCTIONS_H_

#include <iostream>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

struct PiResults {
    float approx;
    float error;
} ;

#include <array>
#include <vector>

#endif

//Function definitions 
PiResults pi_approx (int N);
float* approximations(std::vector<int> n);
