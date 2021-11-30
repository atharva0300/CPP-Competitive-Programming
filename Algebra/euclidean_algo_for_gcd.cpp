#include<bits/stdc++.h>
using namespace std;


// implementation
int gcd(int a , int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b , a%b);
    }
}


// // using ternar operator 
int gcd2(int a , int b)
{
    return b ? gcd2(b ,a%b) : a;
}


// iterative version 
int gcd3(int a , int b)
{
    while(b)
    {
        a = a%b;
        swap(a,b);
    }
    return a;
}


// calculating lcm using gcd 
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int a;
    a =gcd(12,8);
    cout<<a<<"\n";
    cout<<gcd(8,12)<<"\n";
    cout<<gcd2(12,8)<<"\n";

    // using the iterative version 
    cout<<gcd3(12,8)<<"\n";

    // time complexity : O(log min(a,b))

    cout<<lcm(12,8)<<"\n";
    

    return 0;
}