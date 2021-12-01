#include<bits/stdc++.h>
using namespace std;

// Catalan numbers : 
/* 
    Catalan Numbers
Jessie is an artist who's trying to figure out how many different ways she can split a pentagonal sculpture into triangles by adding beams between the pentagon's vertices (with no beams crossing) to determine how the finished sculpture will look. One way Jessie could do this is by drawing all of the possibilities.

But how does Jessie know if her drawings represent all of the possible combinations? As it turns out, there's an easy way to do this: by using Catalan numbers! Catalan numbers are a sequence of positive integers, where the nth term in the sequence, denoted Cn, is found in the following formula:

(2n)! / ((n + 1)!n!)
Here, in the case of all of this, n! is equal to the product of all of the integers from n down to 1:

(n) ⋅ (n - 1) ⋅ (n - 2) ⋅ … ⋅ 2 ⋅ 1

The first few Catalan numbers for n = 0, 1, 2, 3, … are 
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  


Recursive Solution 
Catalan numbers satisfy the following recursive formula. 

C_0=1 \ and \ C_{n+1}=\sum_{i=0}^{n}C_iC_{n-i} \ for \ n\geq 0           


Catalan numebrs : 

C0 = 1
C1 = 1
C2 = C0*C1 + C1*C0 = 1*1 + 1*1 = 2 
C3 = C0*C2 + C1*C1 + C2*C0 = 1*2 + 1*1 + 2*1  5
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0 = 1*5 + 1*2 + 2*1 + 5*1 = 14
...

-*/


// implementation 
unsigned long int catalan(unsigned int n)
{
    // Base case 
    if(n<=1)
    {
        return 1;
    }
    // catalan(n) is sum of 
    // catalan(i)*catalan(n-i-1)
    unsigned long int result = 0;
    for(int i=0;i<n;i++)
    {
        result = result + catalan(i)*catalan(n-i-1);
    }
    return result;
    /*
    Time complexity of above implementation is equivalent to nth catalan number. 

T(n)=\sum_{i=0}^{n-1}T(i)*T(n-i-1) \ for \ n\geq 1;     

The value of nth catalan number is exponential 
that makes the time complexity exponential.
*/
}

// Using dynamic programming 
unsigned long int catalandp(unsigned int n)
{
    // Table to store result of subproblems 
    unsigned long int arr[n+1];

    // initialize first 2 values in table 
    arr[0] = arr[1] = 1;
    
    // Fill entries first 2 values in table 
    for(int i=2;i<=n;i++)
    {
        arr[i] =0;
        for(int j=0;j<i;j++)
        {
            arr[i] = arr[i] + arr[j]*arr[i-j-1];
        }
    }
    

    // return the last entry 
    return arr[n];

    /* .
    Time Complexity: Time complexity of above implementation is O(n2)
    */
}



// Finding the nth Catalan number using Binomial Coefficient 
// with Time complexity : O(n)
unsigned long int binomiacoeff(unsigned int n , unsigned int k)
{
    unsigned long int result = 1;

    // Since C(n,k)  =C(n ,n-k)
    if(k>n-k)
    {
        k = n-k;
    }

    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]

    for(int i=0;i<k;i++)
    {
        result = result * (n-i);
        result = result / (i+1);
    }
    return result;
}


// A binomial Coefficient based function to find the nth catalan 
// number in O(n) time 
unsigned long int catalan3(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomiacoeff(2*n ,n);

    // return 2nCn/(n+1)
    return c/(n+1);

    /* 
    Time Complexity: Time complexity of above implementation is O(n).
We can also use below formula to find nth catalan number in O(n) time. 
*/

}

// practice 
int fun(int n)
{
    int arr[n];
    arr[0] = arr[1] = 1;
    for(int i=2;i<=n;i++)
    {
        arr[i] = 0;
        for(int j=0;j<i;j++)
        {
            arr[i] = arr[i] + arr[j]*arr[i-j-1];
        }
    }
    return arr[n];
}

// Driver code 
int main()
{

    for(int i=0;i<10;i++)
    {
        cout<<catalan(i)<<"\n";
    }
    /* 
    Output
    1 1 2 5 14 42 132 429 1430 4862 
    */

   // calling catalandp 
    cout<<"\nUsing dp\n";
    for(int i=0;i<10;i++)
    {
        cout<<catalandp(i)<<"\n";
    }

    // Calling the catalan3 function 
    cout<<"\nUsing binomial coefficient \n";
    for(int i=0;i<10;i++)
    {
        cout<<catalan3(i)<<"\n";
    }

    cout<<"\nfunc : \n";
    for(int i=0;i<10;i++)
    {
        cout<<fun(i)<<"\n";
    }
    cout<<"\n";
    return 0;
}