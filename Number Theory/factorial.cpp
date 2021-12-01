#include<bits/stdc++.h>
using namespace std;


// Factorial of a number : n*n-1*n-2*n-3*.... *2*1
/* 
    n! = n * (n-1)!
    n! = 1 if n = 0 or n = 1
*/

// Factorial using recursion 
long long fact(long long n)
{
    if(n<2)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    for(long long i=0;i<10;i++)
    {
        cout<<fact(i)<<"\n";
    }
    return 0;
}