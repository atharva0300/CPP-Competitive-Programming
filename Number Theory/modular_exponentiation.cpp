#include<bits/stdc++.h>
using namespace std;

//Given three numbers x, y and p, compute (xy) % p. 

/*  
    Input:  x = 2, y = 3, p = 5
    Output: 3
    Explanation: 2^3 % 5 = 8 % 5 = 3.

    Input:  x = 2, y = 5, p = 13
    Output: 6
    Explanation: 2^5 % 13 = 32 % 13 = 6.
*/

// Iterative function to calculate (x^y) in O(logy)
int power(int x ,int y)
{
    // initialize answer 
    int result = 1;

    // check till the number becomes zero 
    while(y)
    {
        // if y is odd, multiply x with result
        if(y%2==1)
        {
            result = result*x;
        }

        // y = y/2;
        y = y>>1;

        // change x to x^2
        x = (x*x);
    }
    return result;
}

/*
    Efficient Approach:

    The problem with above solutions is, overflow may occur for large value of n or x. 
    Therefore, power is generally evaluated under modulo of a large number.

    Below is the fundamental modular property that is used for efficiently computing 
    power under modular arithmetic. 

    (ab) mod p = ( (a mod p) (b mod p) ) mod p 

    For example a = 50,  b = 100, p = 13
    50  mod 13  = 11
    100 mod 13  = 9

    (50 * 100) mod 13 = ( (50 mod 13) * (100 mod 13) ) mod 13 
    or (5000) mod 13 = ( 11 * 9 ) mod 13
    or 8 = 8
*/


// implementation
// iteartive function to calculate(x^y)%p in O(logy)
int power2(long long x , unsigned int y , int p)
{
    int result = 1;
    //initialize the result 

    x = x%p;
    // update x if it is more than or equal to p

    if(x==0)
    {
        return 0;   // in case x is divisible by p
    }

    while(y>0)
    {
        // if y is odd, multiply x with result 
        if(y&1)
        {
            result = (result*x)%p;
        }

        // y must be even now 
        y = y>>1;   // y = y/2
        x = (x*x)%p;
    }

    return result;
}

//Driver Code
int main()
{
    int x =2;
    int y = 5;
    int p = 13;
    cout<<power(2,3)<<"\n";
    cout<<"Power is : "<<power2(x,y,p)<<"\n";
    return 0;
}