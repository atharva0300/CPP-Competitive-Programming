#include<bits/stdc++.h>
using namespace std;

/* 
    We can calculate the prime factorization of a number “n” in O(sqrt(n)) as 
    discussed here. But O(sqrt n) method times out when we need to answer multiple 
    queries regarding prime factorization.
In this article, we study an efficient method to calculate the prime factorization 
using O(n) space and O(log n) time complexity with pre-computation allowed.
*/

/* 
    To calculate to smallest prime factor for every number we 
    will use the sieve of eratosthenes. In original Sieve, every time
    we mark a number as not-prime, we store the corresponding smallest 
    prime factor for that number (Refer this article for better understanding).

    Now, after we are done with precalculating the smallest prime factor for 
    every number we will divide our number n (whose prime factorization is to 
    be calculated) 
    by its corresponding smallest prime factor till n becomes 1. 
*/

/* 
    Pseudo Code for prime factorization assuming
    SPFs are computed :

    PrimeFactors[] // To store result

    i = 0  // Index in PrimeFactors

    while n != 1 :

    // SPF : smallest prime factor
    PrimeFactors[i] = SPF[n]    
    i++ 
    n = n / SPF[n]
*/


#define MAXN 100001
// stores smallest prime factor for every number
int spf[MAXN];

//calculating SPF(smallest prime factor ) for every 
// number till MAXN
// time complexity : O(nloglogn)

void sieve()
{
    spf[1] = 1;
    for(int i=2;i<MAXN;i++)
    {
        // marking the smallest prime factor for every 
        // numer to be itself
        spf[i] = i;
    }
    // seperately marking spf for every even
    // number as 2

    for(int i=4;i<MAXN;i =i+2)
    {
        spf[i] = 2;
    }

    for(int i=3;i*i<MAXN;i++)
    {
        // checking if i is a prime
        if(spf[i] ==i)
        {
            // making SPF for all numbers divisible by i
            for(int j=i*i;j<MAXN;j = j+i)
            {
                // marking spf[j] if it is not 
                // previously marked 
                if(spf[j]==j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

// A O(logn) function returning primefactorizatin 
// by dividing bty smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int>result;
    while(x!=1)
    {
        result.push_back(spf[x]);
        x = x/spf[x];
    }
    return result;
}


/* 
    Time Complexity: The precomputation for smallest prime factor is 
    done in O(n log log n) using sieve. Whereas in the calculation step 
    we are dividing the number every time by the smallest prime number till 
    it becomes 1. So, let’s consider a worst case in which every time the SPF is 2 . 
    Therefore will have log n division steps. Hence, We can say that our Time 
    Complexity will be O(log n) in worst case.
*/
// driver code
int main()
{
    // precalculating smallest prime factor 
    sieve();
    int x = 12246 ;
    cout<<"Prime factorization of : "<<x<<" : ";
    
    //calling getfactorization function 
    vector<int> p = getFactorization(x);

    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"\n";
    return 0;
}