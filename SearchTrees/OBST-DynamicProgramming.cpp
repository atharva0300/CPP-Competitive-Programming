#include<bits/stdc++.h>
using namespace std;


// a function to get the sum of the array of elements 
// freq[i] to freq[j];
int sum(int freq[], int i , int j);
    
    
    // a dynamic proramming based function that calculates 
    // the minimum cost of a binary search tree
int optimalSearchTtree(int keys[] , int freq[] , int n){
    // create an auxiliary 2D matrix to store results 
    // of subproblems 
    int cost[n][n];

    /* cost[i][j] = Optimal cost of bianry search tree
    that can be found from keys[i] to keys[j]
    cot[0][n-1] will store the resultant cost
    */

   // for a single key, cost is equal to frequency of the key
   for(int i=0;i<n;i++){
       cost[i][i] = freq[i];
   }

   // now we need to consoder chains of length 2,3
   // l is the chain length 
   for(int l=2;l<=n;l++){
       // i is a row number in cost[][]
       for(int i=0;i<=n-l+1;i++){
           // Get column number j from row number i and
            // chain length L
            int j = i+l-1;
            cost[i][j] = INT_MAX;
 
            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
            // c = cost when keys[r] becomes root of this subtree
            int c = ((r > i)? cost[i][r-1]:0) +
                    ((r < j)? cost[r+1][j]:0) +
                    sum(freq, i, j);
            if (c < cost[i][j])
                cost[i][j] = c;
            }
       }
   }

   return cost[0][n-1];
}


// get the sum of the array elements 
// freq[i] to freq[j];
int sum(int freq[] , int i , int j){
    int s= 0;
    for(int k=i;k<=j;k++){
        s+=freq[k];
    }

    return s;
}
int main(){

    int keys[] = {10,12,20};
    int freq[] = {34,8,50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<"Cost of optimal BST : "<<optimalSearchTtree(keys , freq,  n);

    cout<<"\n";

    return 0;
}