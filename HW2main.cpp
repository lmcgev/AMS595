//Main source file for this HW. Runs the functions in the other files.

#include "HW6_functions.h" //import the header file with function defintions
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

int main() {
    //Runs the pi_approx function for N = 1000 and prints the results
    int N = 10000; //sets interval size
    PiResults q1 = pi_approx(N); //calls function
    std::cout << "For N= " << N << ": \n";
    std::cout << "Approx Pi= ";
    printf("%.6f", q1.approx); //prints approximation
    std::cout << "\nError= ";
    printf("%.6f", q1.error); //prints error
    std::cout << "\n";
    
    //Creates a vector as described in the HW problem
    std::vector<int> n(7);
    for (int i=0; i<7; i++){
        n[i] = pow(10, i+1); //adds 10^x for each entry for x = 1:7
    }

    //Runs the approximation function for each value in the vector
    std::cout << "\nApproximations of Pi for 10^x:";
    float* arr = approximations(n); //runs approximation function with vector n input
    for (int i=0; i<7; i++){
        std::cout << "\n" << i+1 << ":";
        printf("%.6f", arr[i]); //prints values of the array
    }
    free(arr); //clears array from memory 
}