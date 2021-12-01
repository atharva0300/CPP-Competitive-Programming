#include<bits/stdc++.h>
using namespace std;


/* 
    To accomplish this task, we define an array d[0…n−1], where d[i] is the length of the longest increasing subsequence that ends in the element at index i. We will compute this array gradually: first d[0], then d[1], and so on. After this array is computed, the answer to the problem will be the maximum value in the array d[].

So let the current index be i. I.e. we want to compute the value d[i] and all previous values d[0],…,d[i−1] are already known. Then there are two options:

d[i]=1: the required subsequence consists of only the element a[i].
d[i]>1: then in the required subsequence is another number before the number a[i]. Let's focus on that number: it can be any element a[j] with j=0…i−1 and a[j]<a[i]. In this fashion we can compute d[i] using the following formula: If we fixate the index j, than the longest increasing subsequence ending in the two elements a[j] and a[i] has the length d[j]+1. All of these values d[j] are already known, so we can directly compute d[i] with:
d[i]=maxj=0…i−1a[j]<a[i](d[j]+1)
If we combine these two cases we get the final answer for d[i]:

d[i]=max⎛⎝⎜1,maxj=0…i−1a[j]<a[i](d[j]+1)⎞⎠⎟

-*/

// implementation 
int lis(vector<int> const &a)
{
    int n= a.size();
    vector<int>d(n,1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                d[i] = max(d[i] , d[j]+1);
            }
        }
    }

    int ans = d[0];
    for(int i=1;i<n;i++)
    {
        ans = max(ans , d[i]);
    }
    return ans;
}



/* 
    RESTORING THE SUBSEQUENCE

    So far we only learned how to find the length of the subsequence, but not how to find the subsequence itself.

To be able to restore the subsequence we generate an additional auxiliary array p[0…n−1] that we will compute alongside the array d[]. p[i] will be the index j of the second last element in the longest increasing subsequence ending in i. In other words the index p[i] is the same index j at which the highest value d[i] was obtained. This auxiliary array p[] points in some sense to the ancestors.

Then to derive the subsequence, we just start at the index i with the maximal d[i], and follow the ancestors until we deduced the entire subsequence, i.e. until we reach the element with d[i]=1.


    IMPLEMENTATION OF RESTORING 

    We will change the code from the previous sections a little bit. We will compute the array p[] alongside d[], and afterwards compute the subsequence.

For convenience we originally assign the ancestors with p[i]=−1. For elements with d[i]=1, the ancestors value will remain −1, which will be slightly more convenient for restoring the subsequence.

*/


// implementation of restoring 

vector<int>lis(vector<int> const &a)
{
    int n = a.size();
    vector<int>d(n,1) , p(n,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && d[i]<d[j]+1)
            {
                d[i] = d[j] + 1;
                p[i] =j;
            }
        }
    }

    int ans = d[0];
    int pos = 0;
    for(int i=1;i<n;i++)
    {
        if(d[i] > ans)
        {
            ans = pos[i];
            pos = i;
        }
    }

    vector<int>subseq;
    while(pos!=-1)
    {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }

    reverse(subseq.begin() , subseq.end());
    return subseq;
}



// Solution in O(nlogn) with dynamic programming and binary search
int lis(vector<int>const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int>d(n+1 , INF);
    d[0] = -INF;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[j-1] < a[i] && a[i] < d[i])
            {
                d[j] = a[i];
            }
        }
    }

    int ans = 0;
    for(int i=0;i<=n;i++)
    {
        if(d[i]<INF)
        {
            ans = i;
        }
    }
    return ans;
}



// Implementation 
int lis(vector<int>const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int>d(n+1 , INF);
    d[0] = -INF ;
    for(int i=0;i<n;i++)
    {
        int j = upper_bound(d.begin() , d.end() , a[i]) - d.begin();
        if(d[j-1] < a[i] && a[i] < d[j])
        {
            d[j] =a[i];
        }
    }

    int ans =0;
    for(int i=0;i<=n;i++)
    {
        if(d[i] <INF)
        {
            ans = i;
        }
    }
    return ans;
}





int main()
{


    return 0;
}
