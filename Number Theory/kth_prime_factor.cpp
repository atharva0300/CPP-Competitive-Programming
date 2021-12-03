#include<bits/stdc++.h>
using namespace std;

// K-th prime factor of a given number 
/* 
    Given two numbers n and k, print k-th prime factor 
    among all prime factors of n. For example, if the input number 
    is 15 and k is 2, then output should be “5”. And if the k is 3, 
    then output should be “-1” (there are less than k prime factors). 
*/

/*
    Input : n = 225, k = 2        
Output : 3
Prime factors are 3 3 5 5. Second
prime factor is 3.

Input : n = 81, k = 5
Output : -1
Prime factors are 3 3 3 3
*/

int kPrimeFactor(int n , int k)
{
    while(n%2==0)
    {
        k--;
        n = n/2;
        if(k==0)
        {
            return 2;
        }
    }
    // n must be odd at this point. So we can skip
    // one element, ( Note i = i +2)
    for(int i=3;i<=sqrt(n);i = i+2)
    {
        while(n%i==0)
        {
            if(k==1)
            {
                return i;
            }
            k--;
            n = n/i;
        }
    }
    // this condition is to handle the case wher e
    // n is a prime number greater than 2 
    if(n>2 && k==1)
    {
        return n;
    }
    return -1;
}


// An effieicnt solution 
/* 
    An Efficient Solution is to use Sieve of Eratosthenes. Note that 
    this solution is efficient when we need k-th prime factor for multiple 
    test cases. For a single case, previous approach is better. 
    The idea is to do preprocessing and store least prime factor of all numbers 
    in given range. Once we have least prime factors stored in an array, we can 
    find k-th prime factor by repeatedly dividing n with least prime factor while 
    it is divisible, then repeating the process for reduced n. 
*/

// implementation
const int MAX = 10001;

// using SieveOfEratosthenes to find the smallest prime 
//facor of all the numbers;
// for example - if MAX is 10,
// s[2] = s[4] = s[6] = s[10] =2;
// s[3] = s[9] = 3;
// s[5] = 5;
// s[7] = 7

void sieveOfEratosthenes(int s[])
{
    // Create a boolean array "prime[0...MAX]" and 
    // initialize all entries in it to false;
    vector<int>prime(MAX+1 ,false);s
    // initializing the smallest factor equal to 2 
    // for all the even numbers
    for(int i=2;i<=MAX;i=i+2)
    {
        s[i] = 2;
    }

    // For odd numbers less than equal to n
    for(int i=3;i<=MAX;i = i+2)
    {
        if(prime[i]==false)
        {
            // s[i] for a prime is the number itself 
            s[i] = i;

            // for all the multiple of current prime number
            for(int j=i;j*i<=MAX;j=j+2)
            {
                if(prime[i*j]==false)
                {
                    prime[i*j] = true;

                    // i is the smallest prime factor for 
                    // number "i*j".
                    s[i*j] = i;
                }
            }
        }
    }
}

// Function to generate prime factors and returns its 
// k-th prime facto. s[i] stores least prime factor 
// of i.
int kPrimeFactor(it n , int k , int s[])
{
    // Keep dividing n by least prime factor while 
    // wither n is not 1 or count of prme factors 
    // is not k
    while(n>1)
    {
        if(k==1)
        {
            return s[n];
        }
        // to keep track of count of prime factors 
        k--;

        // divide n to find next prime factors 
        n = n/s[n];
    }
    return -1;
}


//Driver code 
int main()
{
    int n = 12 ;
    int k =3;
    cout<<kPrimeFactor(5,2)<<"\n";
    cout<<kPrimeFactor(n,k)<<"\n";

    // s[i] is going to store prime factor of i
    int s[MAX+1];
    memst(s ,-1 ,sizeof(s));
    sieveOfEratosthenes(s);

    n=12;
    k=3;
    cout<<kPrimeFactor(n,k,s)<<"\n";
    n=14;
    k=3;
    cout<<kPrimeFactor(n,k,s)<<"\n";
    
    return 0;
}