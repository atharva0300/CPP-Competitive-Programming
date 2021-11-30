// Binary Exponentation 
#include<bits/stdc++.h>
using namespace std;


// Recursive method 
long long binpow(long long a , long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long res = binpow(a, b/2);
    if(b%2)
    {
        return res * res * a;
    }
    else{
        return res * res;
    }
}


// iteartive method 
long long binpow2(long long a , long long b)
{
    long long res = 1;
    while(b> 0)
    {
        if(b & 1) // checking if b is odd
        {
            res = res *a;
        }
        a = a*a;
        b >>=1; // b = b>>1 // right shift b
    }
    return res;
}

int main()
{

    /* 
        TO CALCULATE the exponent of a number 

        a^n = 1 ( if n==0 )
            = (a^n/2)^2  ) ( if n > 2 and n is even ) 
            = (a^(n-1/2)^2)  ( if n > 0 and n is odd )
    */

    // calling the function
    long long a = 12;
    long long b = 3;
    cout<<binpow(a,b)<<"\n";

    cout<<binpow2(a , b)<<"\n";
    return 0;
}