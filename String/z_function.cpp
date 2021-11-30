#include<bits/stdc++.h>
using namespace std;


/* 
    Suppose we are given a string s of length n. The Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters starting from the position i that coincide with the first characters of s.

In other words, z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i.

Note. In this article, to avoid ambiguity, we assume 0-based indexes; that is: the first character of s has index 0 and the last one has index n−1.

The first element of Z-function, z[0], is generally not well defined. In this article we will assume it is zero (although it doesn't change anything in the algorithm implementation).

This article presents an algorithm for calculating the Z-function in O(n) time, as well as various of its applications.

*/


// Trivial Algo 
vector<int>z_function_trivial(string s)
{
    int n = (int) s.length();
    vector<int>z(n);
    for(int i=1;i<n;i++)
    {
        while(i + z[i] , n && s[z[i]]==s[i + z[i]])
        {
            ++z[i];
        }
    }
    return z;
        /* 
        Time complexity : O(n^2 )
        */
}
/*  
    EFFICIENT ALGO 

    To obtain an efficient algorithm we will compute the values of z[i] in turn from i=1 to n−1 but at the same time, when computing a new value, we'll try to make the best use possible of the previously computed values.

For the sake of brevity, let's call segment matches those substrings that coincide with a prefix of s. For example, the value of the desired Z-function z[i] is the length of the segment match starting at position i (and that ends at position i+z[i]−1).

To do this, we will keep the [l,r] indices of the rightmost segment match. That is, among all detected segments we will keep the one that ends rightmost. In a way, the index r can be seen as the "boundary" to which our string s has been scanned by the algorithm; everything beyond that point is not yet known.

Then, if the current index (for which we have to compute the next value of the Z-function) is i, we have one of two options:

i>r -- the current position is outside of what we have already processed.

We will then compute z[i] with the trivial algorithm (that is, just comparing values one by one). Note that in the end, if z[i]>0, we'll have to update the indices of the rightmost segment, because it's guaranteed that the new r=i+z[i]−1 is better than the previous r.

i≤r -- the current position is inside the current segment match [l,r].

Then we can use the already calculated Z-values to "initialize" the value of z[i] to something (it sure is better than "starting from zero"), maybe even some big number.

For this, we observe that the substrings s[l…r] and s[0…r−l] match. This means that as an initial approximation for z[i] we can take the value already computed for the corresponding segment s[0…r−l], and that is z[i−l].

However, the value z[i−l] could be too large: when applied to position i it could exceed the index r. This is not allowed because we know nothing about the characters to the right of r: they may differ from those required.

Here is an example of a similar scenario:

s="aaaabaa"

hus, the whole algorithm is split in two cases, which differ only in the initial value of z[i]: in the first case it's assumed to be zero, in the second case it is determined by the previously computed values (using the above formula). After that, both branches of this algorithm can be reduced to the implementation of the trivial algorithm, which starts immediately after we specify the initial value.

The algorithm turns out to be very simple. Despite the fact that on each iteration the trivial algorithm is run, we have made significant progress, having an algorithm that runs in linear time. Later on we will prove that the running time is linear.

Implementation

*/


// implementation
vector<int>z_function(string s)
{
    int n = (int) s.length();
    vector<int>z(n);
    for(int i=1;l=0;r=0;i<n;i++)
    {
        if(i<=r)
        {
            z[i] = min(r -i+1 , z[i-1]);
        }
        while(i + z[i] < n && s[z[i]]== s[i + z[i]])
        {
            ++z[i];
        }
        if(i +z[i]-1  >r)
        {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

/* 
    The whole solution is given as a function which returns an array of length n -- the Z-function of s.

Array z is initially filled with zeros. The current rightmost match segment is assumed to be [0;0] (that is, a deliberately small segment which doesn't contain any i).

Inside the loop for i=1…n−1 we first determine the initial value z[i] -- it will either remain zero or be computed using the above formula.

Thereafter, the trivial algorithm attempts to increase the value of z[i] as much as possible.

In the end, if it's required (that is, if i+z[i]−1>r), we update the rightmost match segment [l,r].
*/





int main()
{

    return 0;
}