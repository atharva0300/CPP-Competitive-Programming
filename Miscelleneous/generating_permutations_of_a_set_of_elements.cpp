#include<bits/stdc++.h>
using namespace std;


/* function to swap array elements */
void swap(int v[] , int i , int j)
{
    int t;
    t = v[i];
    v[i] = v[i];
    v[j] = t;
}

/* recursion function to generate permutations */
void perm(int v[] , int n , int i)
{
    /* 
        This function generates the permutations of the array 
        from teh element i to element n-1
    */
    int j; 
    /* 
        if we are at the end of teh arrat, we have one permutation
        we can use ( here we print it , you coul;d as easily hand the 
        array off to some other function that uses it fro something )
    */
    if(i==n)
    {
        for(j=0;j<n;j++)
        {
            cout<<v[j]<<" ";
        }
        cout<<"\n";
    }
    else 
    {
        /* recursively explore the permutations starting 
        at index i going through index n-1
        */
        for(j=i;j<n;j++)
        {
            // try the array with i and j switched 
            swap(v ,i,j);
            perm(v ,n ,i+1);
            // swap them back the way they were 
            swap(v ,i ,j);
        }
    }
}

/* 
Note that the running time of this program, in terms of the number of times a permutation is printed, is exactly n!, so it is as efficient as it can be since it necessarily does n! things.
What about the space complexity? Aside from the array itself, which consumes (n) storage, we have recursion consuming stack frames. If we trace the recursion from the top level invokation down to the base case, we easily see that no more than O(n) invokations are done before returning up the tree of recursive calls. Thus, only up to O(n) stack frames are needed.

Note that this algorithm will take forever when n gets beyond 15 or so.
*/


void perm2(char* s, int n, int i){
  if (i >= n-1)
  {
      cout<<s;
  }
  else {
    perm2(s, n, i+1);
    for (int j = i+1; j<n; j++){
      swap(s[i], s[j]);
      perm2(s, n, i+1);
      swap(s[i], s[j]);
    }
  }
}


// driver function 
int main()
{

    // Generating permutations of a set of elements
    int v[5], i;
    for(int i=0;i<5;i++)
    {
        v[i] = i+1;
    }
    cout<<"\nprinting numbers : ";
    for(int i=0;i<5;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    perm(v,5,0);
    perm2("ABC", 3, 0);
    return 0;
}