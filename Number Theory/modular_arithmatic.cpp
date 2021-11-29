/*
    modular arithmatic 
    */
# include<bits/stdc++.h>
using namespace std;

/* 
    Formula : 
    1. (a+b)%M  = ((a%M) + (b%M))%M
    2. (a*b)%M = ((a%M) * (b%M))%M
    3. (a-b)%M = ((a%M) - (b%M) + M)%M
    4. (a/b)%M = ((a%M) * (b^-1)%M)%M
*/



int main()
{
    int n;
    cin>>n;
    int M = 47;
    // stiring factorial
    long long fact  =1;
    for(int i=2;i<=n;i++)
    {
        fact = (fact*i)%M;
    }
    cout<<fact<<"\n";

    /* 
        Why use 10^9 + 7 
            because, the number is very close to integer 
            , so modulo operations can also then , be used for big numbers
        */
    
    
    return 0;
}