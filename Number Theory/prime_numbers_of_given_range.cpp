#include<bits/stdc++.h>
using namespace std;

// Prit prime numnebrs in a given range using C++ STL 

/*
    Input : start = 50 end = 100
Output : 53 59 61 67 71 73 79 83 89 97

Input : start = 900 end = 1000
Output : 907 911 919 929 937 941 947 953 967 971 977 983 991 997
*/

/* 
    Idea is to use Sieve of Eratosthenes as a subroutine. Firstly, 
    find primes in the range from 0 to start and store it in a vector. 
    Similarly, find primes in the range from 0 to end and store in another 
    vector. Now take the set difference of two vectors to obtain the required 
    answer. Remove extra zeros if any in the vector.
*/

// implementation 
typedef unsigned long long int ulli;

vector<ulli> sieve(ulli n)
{
    // Create a boolean vector "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // not a prime, else true
    vector<bool>prime(n+1 ,true);

    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);

    for(ulli i=2;i<=m;i++)
    {
        // if prime[i] is not changedl then it 
        // is a prime 
        if(prime[i])
        {
            // update all multiples of i 
            for(ulli j = i*2;j<=n;j = j+i)
            {
                prime[i] = false;
            }
        }
    }

    // push all the primes into the vector ans 
    vector<ulli>ans;
    for(int i=0;i<n;i++)
    {
        if(prime[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// used to remove zeros from a vector using 
// library function remove_if()
bool zeros(ulli n)
{
    return i==0;
}

vector<ulli>sieveRange(ulli start , ulli end)
{
    // find proims from [0...start] range 
    vector<ulli>s1 =sieve(start);

    // find primes from [0...end] range
    vector<ulli> s2 = sieve(end);

    vector<ulli>ans(end - start);

    // find set difference of 2 vectors and 
    // push result in vecotr ans 
    // O(2*(m+n)-1)
    set_difference(s2.begin() , s2.end() , s1.begin() . s1.end() , ans.begin());

    // remove extra zeros if any ( O(n) ) 
    vector<ulli>::iterator itr = remove_if(ans.begin() , ans.end() , isZero);

    // resize it. // O(n)
    ans.resize(itr-ans.begin());

    return ans;
}

// DRIVER CODE
int main()
{
    ulli start = 50;
    ulli end = 100;
    vector<ulli>ans = sieveRange(start , end);
    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}