#include<bits/stdc++.h>
using namespace std;

/* 
    Let us assume we found the coefficients (x1,y1) for (b,amodb):

b⋅x1+(amodb)⋅y1=g
and we want to find the pair (x,y) for (a,b):

a⋅x+b⋅y=g
We can represent amodb as:

amodb=a−⌊ab⌋⋅b
Substituting this expression in the coefficient equation of (x1,y1) gives:

g=b⋅x1+(amodb)⋅y1=b⋅x1+(a−⌊ab⌋⋅b)⋅y1
and after rearranging the terms:

g=a⋅y1+b⋅(x1−y1⋅⌊ab⌋)
We found the values of x and y:

{x=y1y=x1−y1⋅⌊ab⌋

*/

// implementation 
int gcd(int a,  int b , int &x , int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b , a%b ,x1 , y1);
    x = y1;
    y = x1 -y1*(a/b);
    return d;
}


// iterative version
int gcd(int a , int b , int &x , int &y)
{
    x = 1,y=0;
    int x1=0 ,y1=1 ,a1 =a ,b1=b;
    while(b1)
    {
        int q = a1/b1;
        tie(x ,x1) = make_tuple(x1 ,x-q*x1);
        tie(y, y1) = make_tuple(y1,  y-q*y1);
        tie(a1 ,b1) =make_tuple)b1 , a1-q*b);
    }
    return a1;
}
int main()
{
    
    return 0;
}