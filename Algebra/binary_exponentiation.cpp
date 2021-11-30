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


int bin1(int a , int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        // n is even 
        return bin1(a*a , n/2);
    }
    else
    {
        // n is odd 
        return a * bin1(a*a , (n-1)/2);
    }
}

int bin2(int a , int n)
{
    int result = 1;
    while(n>0)
    {
       if(n%2==1)
       {
           result = result *a;
       }
       a = a*a;
       n = n/2;
    }
    return result;
}


// modular exponentiation - recursive 
int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}


const int M = 1e9 +7;
// modular exponentiation - iterative 
int modularExponentiation2(int x,int n,int M)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
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

    cout<<bin1(a,b)<<"\n";
    cout<<bin2(a,b)<<"\n";

    cout<<modularExponentiation(a,b,M)<<"\n";
    cout<<modularExponentiation2(a,b,M)<<"\n";
    return 0;
}