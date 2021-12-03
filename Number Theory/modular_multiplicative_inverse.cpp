#include<bits/stdc++.h>
using namespace std;


/*  
    Given two integers ‘a’ and ‘m’, find modular multiplicative inverse 
    of ‘a’ under modulo ‘m’.
    The modular multiplicative inverse is an integer ‘x’ such that.

    a x ≅ 1 (mod m) 

    The value of x should be in { 1, 2, … m-1}, i.e., in the range of 
    integer modulo m. ( Note that x cannot be 0 as a*0 mod m will never be 1 )
    The multiplicative inverse of “a modulo m” exists if and only if a and m 
    are relatively prime (i.e., if gcd(a, m) = 1).
*/

/*  
    Input:  a = 3, m = 11
Output: 4
Since (4*3) mod 11 = 1, 4 is modulo inverse of 3(under 11).
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {1, 2, ... 10}, so not 
valid.

Input:  a = 10, m = 17
Output: 12
Since (10*12) mod 17 = 1, 12 is modulo inverse of 10(under 17).
*/


// Naive method 
/*
    A naive method is to try all numbers from 1 to n. For evey number x, check if (a*x)%m is 1 
*/
// implementation
int modInverse(int a, int m)
{
    for(int i=1;i<m;i++)
    {
        if(((a%m)*(i%m))%m==1)
        {
            return i;
        }
    }

    // Time complexity : O(m)
}


// Method 2 ( works when m and a are coprime )
/* 
    The idea is to use Extended Euclidean algorithms that takes two integers 
    ‘a’ and ‘b’, finds their gcd and also find ‘x’ and ‘y’ such that : 
    ax + by = gcd(a, b)

    To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula. 
    Since we know that a and m are relatively prime, we can put value of gcd as 1.
    ax + my = 1
    If we take modulo m on both sides, we get
    ax + my ≅ 1 (mod m)

    We can remove the second term on left side as 
    ‘my (mod m)’ would always be 0 for an integer y. 

    ax  ≅ 1 (mod m)
    So the ‘x’ that we can find using 
    Extended Euclid Algorithm is the multiplicative inverse of ‘a’
*/



// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);


// Function to find modulo inverse of a
void modInverse2(int a , int m)
{
    int x ,y;
    int g = gcdExtended(a,m,&x,&y);
    if(g!=1)
    {
        cout<<"Inverse dosen'y exist";
    }
    else{
        // m is added to handle negative x
        int result = (x%m + m) %m;
        cout<<"Modular multiplicative Inverse is : "<<result;
    }
}

// Function for extended Euclidean algorithm
int gcdExtended(int a , int b , int* x , int* y)
{
    // Base Case 
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }

    //To store results of recursive call 
    int x1, y1;
    int gcd = gcdExtended(b%a ,a ,&x1 , &y1);

    // update x and y using results of recursive 
    // call
    *x = y1 - (b/a)*x1;
    *y = x1;

    return gcd;
}



// iterative implementation 
// returns modulo inverse of a with respect 
// to m using extended euclid algo
// assumption ; a and m are coprimes. ie -gcd(a,m)=1
int modInverse3(int a , int m)
{
    int m0 =m;
    int y=0;
    int x=1;
    if(m==1)
    {
        return 0;
    }

    while(a>1)
    {
        // q is quotient 
        int q = a/m;
        int t = m;

        // m is remainder now, process same as 
        // euclid's algo
        m =a%m;
        a = t;
        t =y;

        // update y and x 
        y = x-q*y;
        x=t;
    }
    // make x positive 
    if(x<0)
    {
        x = x+m0;
    }
    return x;
    // Time Complexity: O(Log m)
}



/* 
    Method 3 (Works when m is prime) 
    If we know m is prime, then we can also use Fermats’s little theorem 
    to find the inverse. 

    am-1 ≅ 1 (mod m)
    If we multiply both sides with a-1, we get 

    a-1 ≅ a m-2 (mod m)
*/
// to find GCD of a and b
int gcd(int a , int b);

// to compute x raised to power y under modulo m
int power(int x , unsigned int y , unsigned int m);

// Function to find modular inverse of a under modulo m
// Assumption : m is prime 
void modInverse4(int a , int m)
{
    int g = gcd(a,m);
    if(g!=1)
    {
        cout<<"\nInverse dosen't exist\n";
    }
    else
    {
        // if a and m are relatively prime , then modulo 
        // inverse is a^(m-2)mod(m)
        cout<<"Modular multiplicative inverse is : "<<power(a,m-2,m)<<"\n";
    }
    // Time Complexity: O(Log m)
}

// To compute x^y under modulo m
int power(int x , unsigned int y , unsigned int m)
{
    if(y==0)
    {
        return 1;
    }
    int p = power(x ,y/2 ,m)%m;
    p = (p*p)%m;

    return (y%2==0) ? p : (x*p)%m;
}

// Function to return gcd of a and b
int gcd(int a , int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a , a);
}



//Driver Code 
int main()
{
    int a = 3;
    int m = 11;
    //Function call 
    cout<<modInverse(3,11)<<"\n";
    modInverse2(a,m);
    cout<<"\n";
    cout<<"Modular multiplicative inverse is : "<<modInverse3(a,m)<<"\n";
    modInverse4(a,m);
    cout<<"\n";
    return 0;

    /* 
        We have discussed three methods to find multiplicative inverse modulo m. 
        1) Naive Method, O(m) 
        2) Extended Euler’s GCD algorithm, O(Log m) [Works when a and m are coprime] 
        3) Fermat’s Little theorem, O(Log m) [Works when ‘m’ is prime]
    */
}