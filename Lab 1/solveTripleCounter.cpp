/*
 This program solves a recursive equation. It outputs
 an algebraic equation with recursion. The essential
 variable of this program is integer n, it changes
 recursively within the recursive function.
 
 @author: Bixia Deng
 @version: 09/10/18
 @assignment: Lab 1b
 @Editor: Xcode
 @instructor: Samuel Johnson
 */

#include <iostream>
using namespace std;

int solveTripleCounter(int n);

int main()
{
    cout << "n is 2 = 3: " << solveTripleCounter(2) << endl;
    cout << "n is 3 = 7: " << solveTripleCounter(3) << endl;
    cout << "n is 4 = 15: " << solveTripleCounter(4) << endl;
}

/*
 Function takes in one integer parameter into a recursive function
 of T(n) = T(n-1) + 1 + T(n-1). The base cases are if n is equal to
 1, return 0; return 1 if n equals to 1. The recursive step is call
 itself with n-1 twice and plus 1. The algebraic function is F(n) = 2^n - 1.
 
 @param n - an integer value
 @return integer - output of the equation
 */
int solveTripleCounter(int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return solveTripleCounter(n-1) + solveTripleCounter(1) + solveTripleCounter(n-1);
}
