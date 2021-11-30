#include<bits/stdc++.h>
using namespace std;


/* 
    Sieve of Eratosthenes - 

    You can use the Sieve of Eratosthenes to find all the prime numbers that are less than or equal to a given number N or to find out whether a number is a prime number.

The basic idea behind the Sieve of Eratosthenes is that at each iteration one prime number is picked up and all its multiples are eliminated. After the elimination process is complete, all the unmarked numbers that remain are prime.

Pseudo code

Mark all the numbers as prime numbers except 1
Traverse over each prime numbers smaller than sqrt(N)
For each prime number, mark its multiples as composite numbers
Numbers, which are not the multiples of any number, will remain marked as prime number and others will change to composite numbers.

*/

void sieve(int n)
{
    bool isPrime[n+1];
    for(int i=0;i<=n;i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i =2;i<sqrt(n);i++)
    {
        if(isPrime[i]==true)
        {
            // Mark all the multiples of the composite number
            for(int j = i;j<=sqrt(n);j = j+i)
            {
                isPrime[j] = false;
            }
        }
    }

    /* 
    Time complexity -
    The inner loop that runs for each element is as follows:

    If i = 2, inner loop runs N / 2 times
    If i = 3, inner loop runs N / 3 times
    If i = 5, inner loop runs N / 5 times
    Total complexity

    N * (½ + ⅓ + ⅕ + … ) = O(NloglogN)

*/
}



// Modification of sieve of Eratosthenes for fast factorization 
vector<int>factorize(int n)
{
    vector<int>res;
    for(int i=2;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            res.push_back(i);
            n = n /i;
        }
    }
    if(n!=1)
    {
        res.push_back(n);
    }
    return res;
}


/* 
Let us construct an array which will give us this number in O(1) time.
*/
int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}

// Now we use this modification to factorie N in O(logn) time;
vector<int>factorize2(int n)
{
    vector<int>res;
    while(n!=1)
    {
        res.push_back(minPrime[n]);
        n = n/ minPrime[n];
    }
    return res;
}

int main()
{
    vector<int>p;
    p = factorize(50);
    for(auto x : p)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    vector<int>q;
    q = factorize2(50);
    for(auto x : q)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}