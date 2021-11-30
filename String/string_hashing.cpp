#include<bits/stdc++.h>
using namespace std;


long long compute_hash(string const&s)
{
    const int p =31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for(char c : s)
    {
        hash_value = (hash_value + (c- 'a' + 1)*p_pow) %m;
        p_pow= (p_pow * p)%m;
    }
    return hash_value;
}

/* 
    Problem: Given a list of n strings si, each no longer than m characters, find all the duplicate strings and divide them into groups.

    From the obvious algorithm involving sorting the strings, we would get a time complexity of O(nmlogn) where the sorting requires O(nlogn) comparisons and each comparison take O(m) time. However, by using hashes, we reduce the comparison time to O(1), giving us an algorithm that runs in O(nm+nlogn) time.

    We calculate the hash for each string, sort the hashes together with the indices, and then group the indices by identical hashes.

*/

vector<vector<int>> group_identical_strings(vector<string const &s)
{
    int n = s.size();
    vector<pair<long long , int>> hashes(n);
    for(int i=0;i<n;i++)
    {
        hashes[i] = {compute_hash(s[i]) ,i};
    }

    sort(hashes.begin() , hashes.end());

    vector<vector<int>>groups;
    for(int i=0;i<n;i++)
    {
        if(i==0 || hashes[i].first!=hashes[i-1].first)
        {
            groups.emplace_back();
        }
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}


/*
    Determine the numer of differece substrings in a string 

    Problem: Given a string s of length n, consisting only of lowercase English letters, find the number of different substrings in this string.

To solve this problem, we iterate over all substring lengths l=1…n. For every substring length l we construct an array of hashes of all substrings of length l multiplied by the same power of p. The number of different elements in the array is equal to the number of distinct substrings of length l in the string. This number is added to the final answer.

For convenience, we will use h[i] as the hash of the prefix with i characters, and define h[0]=0.

*/
int count_unique_substring(string const&s)
{
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long>p_pow(n);
    p_pow[0] = 1;
    for(int i=1;i<n;i++)
    {
        p_pow[i] = (p_pow[i-1] * p)%m;
    }
    vector<long long> h(n+1 ,0);
    for(int i=0;i<n;i++)
    {
        h[i+1] = (h[i] + (s[i] - 'a' +1) * p_pow[i])%m;
    }

    int cnt = 0;
    for(int l=1;l<=n;l++)
    {
        set<long long>hs;
        for(int i=0;i<=n-1;i++)
        {
            long long cur_h = (h[i+l] + m -h[i])%m;
            cur_h = (cur_h * p_pow[n-i-1])%m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}


int main()
{
    /* 
        string hashing 
        an algo to efficiently comparing 2 strings 
        by converting the string into hash values and then 
        comparing the hash value ( O(1) ) operation.

        formula to convert string to hash value - 
        hash(s)=s[0]+s[1]⋅p+s[2]⋅p2+...+s[n−1]⋅pn−1modm=∑i=0n−1s[i]⋅pimodm,

        where p and m aare some chosen, positive numbers ;

        Precomputing the powers of p might give a performance boost.

    */  


    return 0;
}