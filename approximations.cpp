//Code for Question 2 on the HW
#include "HW6_functions.h" //import header file
#include <array> //import vector and array to use vector and array data structures
#include <vector>

//function that uses dynamically allocated C array to return an array of approximations
float* approximations(std::vector<int> n){ //defines function and specficies a vector as input
    float* ap_arr = (float*) malloc(sizeof(float) * n.size()); //This line allows for dynamic memory allocation and specifies an array of type float will be returned
    /*Estimates pi using the the pi_approx function for every element in a user inputted vector. 

    for loop goes through each element of the vector and runs pi_approx

    All stored and returned in a dynamically allocated array
    */
    
    //creates array of pi approximations for each value in vector
    for (int i=0; i < n.size(); i++){
        ap_arr[i] = pi_approx(n[i]).approx;
    }
    
    return ap_arr;
}