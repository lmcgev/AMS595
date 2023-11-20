#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Question 2
/*The following function takes a vector of integers and displays it with brackets to be used in following questions. 
The for loop goes through the indexes of the vector and prints them*/
void print_vector(vector<int> v){
   cout << "\n[ ";
   for (int i : v){
    cout << i << " ";
   }
   cout << "]" << "\n";
}

//Question 4a
/*The Following function takes in an integer and returns if its prime by dividing it by every value between 2 and sqrt(n) and returning
false if the remainder of the divison is 0*/
bool isprime(int n) {
    bool result;
    //checks if number if 0, negative, or 1 (all not prime)
    if (n <= 0 || n == 1) {
        return false;
    }
    
    result = true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) {
            result = false;
        }
    }

    return result;
}

//Question 4a Test Code
void test_isprime() {
std::cout << "isprime(2) = " << isprime(2) << '\n';
std::cout << "isprime(10) = " << isprime(10) << '\n';
std::cout << "isprime(17) = " << isprime(17) << '\n';
}

//Question 4b 
/*The following function computes a factorization of an integer by starting with an intialized vector of just 1 then going through 
each number between 2 and n and checking if n divided by that number has a 0 remainder. if it does it's added to the vector*/
vector<int> factorize(int n) {
    vector<int> answer;
    answer.push_back(1);
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }
    return answer;
}

//Question 4b Test Code
void test_factorize() {
print_vector(factorize(2));
print_vector(factorize(72));
print_vector(factorize(196));
}

//Question 4c 
/*The following function also computes a factorization, but now a prime facotrization. 1 is not a prime number so it returns a blank
vector. If a number is prime a vector containing n is returned. Otherwise the main algoirthm uses a for loop to go through every number between 2
and n. Then a if loop checks that number is prime. If it is a while loop is started that keeps dividing n by that number, adding that
number to a vector when the ramainder is 0 and stopping the loop when it no longer is */
vector<int> prime_factorize(int n) {
    vector<int> answer;
    if (n == 1) {
        return answer;
    }
    else if (isprime(n)) {
        answer.push_back(n);
        return answer;
    }

    for (int i = 2; i <= n; i++) {
        if (isprime(i)) {
            while (n % i == 0) {
                n = n / i;
                answer.push_back(i);
            }
        }
    }
    return answer;
}

//Question 4c Test Code
void test_prime_factorize() {
print_vector(prime_factorize(2));
print_vector(prime_factorize(72));
print_vector(prime_factorize(196));
}

//Question 5
/*The following function returns the first n rows (start at 0) of pascals triangle. Base case of row 0 is given. The top row is intialized as
row 2 [1, 1]. Then a while loop is used to increment through each row. At each row step a for loop calculates the values of the current row by setting
each value of the current row to the i + the i-1 entry of the above row. */
void pascals(int n) {
    if (n < 0 ) {
        return;
    }

    vector<int> top{1};
    cout << "Row 0: ";
    print_vector(top);

    if (n > 1) {
        top = {1, 1};
        cout << "Row 1: ";
        print_vector(top);

        int c = 2;
        while (c <= n) {
            vector<int> below {1};
            for (int i = 1; i < top.size(); i++) {
                below.push_back(top[i-1] + top[i]);
            }
            below.push_back(1);
            cout << "Row " << ++c - 1 << ": ";
            print_vector(below);
            top = below;
        }
    }
}


int main()
{
    //Question 1
    //Question 1 is simply a C++ translation of the MATLAB code
    cout << "Question 1" << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    switch (n){
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
    }
    cout << "\n";

    //Question 3
    /*The following code calcuates the values of the fibaoci sequence from 1 to less than 4000000. This is done by initializing the vector to 1, and the 
    leading value, or "head", to 2. A while loop then continually adds the head to the vector, resets the head to the summation of the last two values
    in the vector, and repeats until the head is above 4000000*/
    cout << "Question 3" << endl;

    vector<int> fib {1};
    int head = 2;
    while (head <= 4000000) {
        fib.push_back(head);
        head = fib[fib.size()-1] + fib[fib.size()-2];
    } 
    cout << "The values of the fibonacci seq: ";
    print_vector(fib);
    cout << "\n";

    //Question 4a Test Code Call
    cout << "Question 4a" << endl;
    test_isprime();
    cout << "\n";

    //Question 4b Test Code Call
    cout << "Question 4b" << endl;
    cout << "Factorizations: ";
    test_factorize();
    cout << "\n";

    //Question 4c Test Code Call
    cout << "Question 4c" << endl;
    cout << "Prime Factorizations: ";
    test_prime_factorize();
    cout << "\n";

    //Question 5
    //Asks for an input for x, which is the number that will be used in calling the function written for Q5
    cout << "Question 5" << endl;
    int x;
    cout << "Enter Rows of Pascals Tri to Output: ";
    cin >> x;
    pascals(x);
    cout << "\n";
}

