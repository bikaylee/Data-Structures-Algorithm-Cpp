/*
 This program is based on the outputs to write recursion.
 The essential variables are integer n and m. The first
 parameter n breaks down to 1 + 1 +...+ 1 and add
 the parameter recursively with the other parameter m.
 
 @author: Bixia Deng
 @version: 09/10/18
 @assignment: Lab 1c
 @Editor: Xcode
 @instructor: Samuel Johnson
 */

#include <iostream>
using namespace std;

int sum(int n, int m);

int main()
{
    cout << "0 + 0 = 0: " << sum(0, 0) << endl;
    cout << "0 + 1 = 1: " << sum(0, 1) << endl;
    cout << "1 + 3 = 4: " << sum(1, 3) << endl;
    cout << "2 + 2 = 4: " << sum(2, 2) << endl;
    cout << "3 + 4 = 7: " << sum(3, 4) << endl;
    cout << "4 + 10 = 14: " << sum(4, 10) << endl;
    cout << "7 + 10 = 17: " << sum(7, 10) << endl;
    cout << "23 + 10 = 33: " << sum(23, 10) << endl;
    cout << "392 + 12 = 404: " << sum(392, 12) << endl;
}




/*
 Function returns a sum of two integer. We are only recursively
 adding the first parameter. The base case is: If n is 0, then
 the sum must equal to m. The base case for n is: if n is 1 and
 m is 0 then return 1. Because m does not add up recursively, we
 set the m to 0 in the recursive step. The recursive step for the
 whole function is m plus recursive addition of n-1 and plus one.
 
 Precondition: parameters are non negative integers
 Postcondition: returns an integer which is the sum of the two parameters
 */
int sum(int n, int m)
{
    if(n == 0)
        return m;
    else if (n == 1 && m == 0)
        return 1;
    else
        return m + sum(n-1, 0) + 1;
}

