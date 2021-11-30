#include<bits/stdc++.h>
using namespace std;


/*
    Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] using O(nloglogn) operations.

The algorithm is very simple: at the beginning we write down all numbers between 2 and n. We mark all proper multiples of 2 (since 2 is the smallest prime number) as composite. A proper multiple of a number x, is a number greater than x and divisible by x. Then we find the next number that hasn't been marked as composite, in this case it is 3. Which means 3 is prime, and we mark all proper multiples of 3 as composite. The next unmarked number is 5, which is the next prime number, and we mark all proper multiples of it. And we continue this procedure until we processed all numbers in the row.

In the following image you can see a visualization of the algorithm for computing all prime numbers in the range [1;16]. It can be seen, that quite often we mark numbers as composite multiple times.

*/



int main()
{
    // implementation
    int n;
    vector<bool>is_prime(n+1 ,true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i] && (long long)i*i <=n)
        {
            for(int j=i*i;j<=n;j += i)
            {
                is_prime[j] = false;
            }
            
        }
    }

    // sieving till root 
    return 0;
}