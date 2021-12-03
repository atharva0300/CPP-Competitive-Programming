#include<bits/stdc++.h>
using namespace std;

/* 
    Given an integer n. Find politeness of number n. 
    The politeness of a number is defined as the number of ways it can 
    be expressed as the sum of consecutive integers. 
*/

/*  
    Input: n = 15
    Output: 3
    Explanation:
    There are only three ways to express
    15 as sum of consecutive integers i.e.,
    15 = 1 + 2 + 3 + 4 + 5
    15 = 4 + 5 + 6
    15 = 7 + 8
    Hence answer is 3

    Input: n = 9;
    Output:  2
    There are two ways of representation:
    9 = 2 + 3 + 4
    9 = 4 + 5
*/

//Naive Approach 
/* 
    Run a loop one inside another and find the sum of every 
    consecutive integer up to n. The time complexity of this approach will be 
    O(n2) which will not be sufficient for large value of n.
*/


// Efficient Approach 
/*
    Use factorization. We factorize the number n and count the number of odd 
    factors. A total number of odd factors (except 1) is equal to the politeness of 
    the number. Refer this for proof of this fact. In general, if a number can be 
    represented as ap * bq * cr … where a, b, c, … are prime factors of n. If a = 2 
    (even) then discard it and count total number of odd factors which can be written
    as [(q + 1) * (r + 1) * …] – 1 (Here 1 is subtracted because single term in 
    representation is not allowed). 
    How does the above formula work? The fact is if a number is expressed 
    as ap * bq * cr … where a, b, c, … are prime factors of n, then a number 
    of divisors is (p+1)*(q+1)*(r+1) …… 
    To simplify, let there be one factor, and the number is expressed as ap. 
    Divisors are 1, a, a2, …. ap. The count of divisors is p+1. Now let us 
    take a slightly more complicated case apbp. The divisors are : 
    1, a, a2, …. ap 
    b, ba, ba2, …. bap 
    b2, b2a, b2a2, …. b2ap 
    ……………. 
    ……………. 
    bq, bqa, bqa2, …. bqap
    The count of the above terms is (p+1)*(q+1). Similarly, we can prove for 
    more prime factors.
    Illustration : For n = 90, decomposition of prime factors will be as follows:- 
    => 90 = 2 * 32 * 51. The power of odd prime factors 3, 5 are 2 and 1 
    respectively. Apply above formula as: (2 + 1) * (1 + 1) -1 = 5. Hence 5 will 
    be the answer. We can crosscheck it. All odd factors are 3, 5, 9, 15 and 45.

*/

//implementation
int countOddPrimeFactors(int n)
{
    int result = 1;
    // eliminate all even prime 
    // factor of number of n
    while(n%2==0)
    {
        n = n/2;
    }

    // n must be odd at this point,
    // so iterate for only 
    // odd numbers itll sqrt(n)

    for(int i=3;i*i<=n;i =i+2)
    {
        int divCount=0;

        // if i divides n, then start counting of 
        // odd divisors
        while(n%i==0)
        {
            n = n/i;
            divCount++;
        }
        result = result * (divCount +1);
    }
    if(n>2)
    {
        result = result *2;
    }
    return result;

    /*  
    Time complexity: O(sqrt(n)) 
    Auxiliary space: O(1)
*/
}


int politeness(int n)
{
    return countOddPrimeFactors(n)-1;


}


//Another efficient approach 
/*
    Calculate if an AP can be generated for the given length domain [2, sqrt(2*n)]. The reason to calculate for length till sqrt(2*n) is-

max length will be for the AP 1, 2, 3…

*/

/* 
    Length for this AP is -

n= ( len * (len+1) ) / 2

len2 + len - (2*n) =0

so len≈sqrt(2*n) 

*/

/*
    so we can check for each len from 1 to sqrt(2*n) ,if AP can be generated with this len. The formula to get the first term of the AP is –

n= ( len/2) * ( (2*A1) + len-1 )
*/


// Fucntio to fid politeness 
int politeness2(int n )
{   
    int count=0;
    // sqrt(2*n) as max length 
    // will be when the sum starts 
    // from 1
    // which follows the equatio n^2 - n -(2*sum) =0
    for(int i=0;i<sqrt(2*n);i++)
    {
        int a;
        if((2*n)%i!=0)
        {
            continue;
        }
        a = 2*n;
        a = a/i;
        a = a - (i-1);
        if(a%2!=0)
        {
            continue;
        }
        a =a/2;
        if(a>0)
        {
            count++;
        }
    }
    return count;

    /*  
    Time complexity:  O(sqrt(2*n)) ≈ O(sqrt(n))                                                                                                                                Auxiliary space: O(1)     
    */
}


// driver code
int main()
{
    int n = 90;
    cout<<"Politeness of "<<n<<" = "<<politeness(n)<<"\n";
    cout<<"Politeness of "<<n<<" = "<<politeness2(n)<<"\n";

    n = 15;
    cout<<"Politeness of "<<n<<" = "<<politeness(n)<<"\n";
    cout<<"Politeness of "<<n<<" = "<<politeness2(n)<<"\n";



    return 0;
}