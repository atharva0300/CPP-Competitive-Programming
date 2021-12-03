#include<bits/stdc++.h>
using namespace std;

/* 
 Input : n = 10       
 Output: 1 2 5 10

 Input:  n = 100
 Output: 1 2 4 5 10 20 25 50 100

 Input:  n = 125
 Output: 1 5 25 125
 */

//Naive method
void printDivisors(int n)
{
    for(int i=0;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
        }
    }
    /* 
    Time Complexity : O(n) 
    Auxiliary Space : O(1)
*/
}

/* 
    Can we improve the above solution? 
If we look carefully, all the divisors are present in pairs. 
For example if n = 100, then the various pairs of divisors are: 
(1,100), (2,50), (4,25), (5,20), (10,10)
Using this fact we could speed up our program significantly. 
We, however, have to be careful if there are two equal divisors 
as in the case of (10, 10). In such case, we’d print only one of them. 
*/

// Function to print the divisors 
void printDivisors2(int n)
{
    //Note that this loop runs till square root 
    for(int i=0;i<n;i++)
    {
        if(n/i==i)
        {
            // if divisors are equal, print only one
            cout<<i<<" ";
        }
        else
        {
            // otherwise print both 
            cout<<" "<<i<<" "<<n/i;
        }
    }
    /* 
        Time Complexity: O(sqrt(n)) 
    Auxiliary Space : O(1)
*/
}


int main()
{
    printDivisors(50);
    cout<<"\n";
    printDivisors2(50);
    cout<<"\n";
    return 0;
}