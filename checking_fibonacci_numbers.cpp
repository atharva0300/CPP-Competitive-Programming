#include<bits/stdc++.h>
using namespace std;

/*  
    Given a number ‘n’, how to check if n is a Fibonacci number. 
    First few Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, .. 
*/

/* 
    Examples : 
 

Input : 8
Output : Yes

Input : 34
Output : Yes

Input : 41
Output : No
*/

/* 
    NOTE : A number is fibonacci if and only if one or both of (5*n^2+4) or (5*n^2-4)
    is a perfect square. 
*/

bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s==x);
}

// returns true if n is a fibonacci number, else false 
bool isFibonacci(int n)
{
    // n is fibonacci if one of 5*n*n + 4 -4 or both 
    // is a perfect square 
    return isPerfectSquare(5*n*n+4) || isPerfectSquare(5*n*n-4);

    /* 
        Time Complexity: O(n)

        Auxiliary Space: O(1)
    */
}

// Driver Code
int main()
{
    for(int i=1;i<=10;i++)
    {
        isFibonacci(i) ? cout<<i<<" is a Fibonacci number\n" : cout<<i<<" is not a fibonacci number\n";
    }
    cout<<"\n";
    return 0;
}