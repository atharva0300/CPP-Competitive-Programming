#include<bits/stdc++.h>
using namespace std;

/* 
    Given a numebr n , prit all primes smaller than or equal to n 
*/

/*  
    Examples: 
 

Input:  n = 10
Output: 2, 3, 5, 7

Input:  n = 20
Output: 2, 3, 5, 7, 11, 13, 17, 19
*/

/*
    printPrimes(n)
[Prints all prime numbers smaller than n]

1) In general Sieve of Sundaram, produces primes smaller than 
   (2*x + 2) for a number given number x. Since we want primes 
   smaller than n, we reduce n-1 to half. We call it nNew.
       nNew = (n-1)/2;
   For example, if n = 102, then nNew = 50.
                if n = 103, then nNew = 51

2) Create an array marked[n] that is going 
   to be used to separate numbers of the form i+j+2ij from 
   others where  1 <= i <= j

3) Initialize all entries of marked[] as false.

4) // Mark all numbers of the form i + j + 2ij as true
   // where 1 <= i <= j
   Loop for i=1 to nNew
        a) j = i; 
        b) Loop While (i + j + 2*i*j)  2, then print 2 as first prime.

6) Remaining primes are of the form 2i + 1 where i is
   index of NOT marked numbers. So print 2i + 1 for all i
   such that marked[i] is false. 
*/


// implementation 
void sieveOfSundaram(int n)
{
    // in general sieve of sundaram, produces primes smaller 
    // than (2*x + 2) for a number given number x.
    // Since we watn primes smaller than n, we reduce n to half 
    int nNew = (n-1)/2;

    // This array is used to seperate numbers of the form i+j+2ij
    // from others where 1<=i<=j
    bool marked[nNew + 1];

    // initialize all elements as not marked 
    memset(marked ,false , sizeof(marked));

    // main logic of sundaram Mark all numbers of the 
    // from i+j+2ij as true where 1<=i<=j
    for(int i=1;i<=nNew;i++)
    {
        for(int j=i;(i+j+2*i*j)<=nNew;j++)
        {
            marked[i+j+2*i*j] = true;
        }
    }

    // since 2 is a prime number
    if(n>2)
    {
        cout<<2<<" ";
    }

    // Print other primes. Remaining primes are of the form
    // 2*i +1 such that marked[i] is false 
    for(int i=1;i<=nNew;i++)
    {
        if(marked[i]==false)
        {
            cout<<2*i+1<<" ";
        }
    }

    /*
    All red entries in below illustration are marked entries. 
    For every remaining (or black) entry x, the number 2x+1 is prime.
    Lets see how it works for n=102, we will have the sieve for (n-1)/2 as follows: 
    Mark all the numbers which can be represented as i + j + 2ij
    Now for all the unmarked numbers in the list, find 2x+1 and that will be the prime: 
    Like 2*1+1=3 
    2*3+1=7 
    2*5+1=11 
    2*6+1=13 
    2*8+1=17 and so on..

    When we produce our final output, we produce all integers of the form 2x+1 (i.e., they are odd) except 2 which is handled separately.
 

    Let q be an integer of the form 2x + 1.

    q is excluded if and only if x is of the 
    form i + j + 2ij. That means, 

    q = 2(i + j + 2ij) + 1
    = (2i + 1)(2j + 1)

    So, an odd integer is excluded from the final list if 
    and only if it has a factorization of the form (2i + 1)(2j + 1)
    which is to say, if it has a non-trivial odd factor. 
    */
}

//Driver code 
int main()
{
    int n = 20;
    sieveOfSundaram(n);
    cout<<"\n";
    return 0;
}