#include<bits/stdc++.h>
using namespace std;


/* 
    You are given a string s of length n. The prefix function for this string is defined as an array π of length n, where π[i] is the length of the longest proper prefix of the substring s[0…i] which is also a suffix of this substring. A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0.

    Mathematically the definition of the prefix function can be written as follows:

    π[i]=maxk=0…ik:s[0…k−1]=s[i−(k−1)…i]
    For example, prefix function of string "abcabcd" is [0,0,0,1,2,3,0], and prefix function of string "aabaaab" is [0,1,0,1,2,2,3].

*/

/* 
    Trivial Algorithm 
*/

vector<int>prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=i;k++)
        {
            if(s.substr(0,k) == s.substr(i-k+1 , k))
            {
                pi[i] = k;
            }
        }
    }
    return pi;
    /* 
    It is easy to see that its complexity is O(n3), which has room for improvement.
    */
}

// Efficiet Implementation
vector<int>prefix_function(string s)
{
    int n = (int)s.length();
    vector<int>pi(n);
    for(int i=1;i<n;i++)
    {
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j = pi[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;

    // time omplexity of the KMP algo - O( m+n )
}

// Counting the number of occurences of each prefix 
vector<int>ans (n+1);
for(int i=0;i<n;i++)
{
    ans[pi[i]]++;
}
for(int i=n-1;i > 0;i--)
{
    ans[pi[i]] += ans[i];
}
for(int i=0;i<=n;i++)
{
    ans[i]++;
}

int main()
{

    return 0;
}