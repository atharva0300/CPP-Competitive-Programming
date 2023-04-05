#include<bits/stdc++.h>
using namespace std;


// function to get the sum of the array elements 
int sum(int freq[] , int i , int j);

// a recirsize function to calculate 
// cost of the optimal binary search tree 
int optCost(int freq[] , int i , int j){
    // base case 
    if(j<i){
        // no elements in this subarray 
        return 0;
    }if(j==i){
        // one element in this subarray 
        return freq[i];
    }

    // get sum of freq[i] , freq[i+1]... freq[j]
    int fsum = sum(freq , i , j);

    // initialize minimum value 
    int min = INT_MAX;

    // one by one, consider all the elements 
    // as root and recursively find cost 
    // of teh BST, compare the cost with 
    // min and the update min if needed
    for(int r=i;r<=j;r++){
        int cost = optCost(freq ,i , r-1) + optCost(freq , r+1 , j);

        if(cost < min){
            min= cost;
        }    
    }


    // return the minimum vlaue 
    return min + fsum;

}


// the mian function that calculates 
// minimum cost of a Binary search tree
 // it mainly uses optCost() to find 
 // the optimal cost 
 int optimalSearchTree(int keys[] , int freq[] , int n){
     // here array keys[] is assumed to be 
     // sorted in increasing order. If keys[] 
     // is not sorted, then add code to sort 
     // key , and rearrange, freq[] , accordingly.
     return optCost(freq , 0 , n-1);
 }

 // a utility function to get sum of 
 // array elements freq[i] to freq[j];
 int sum(int freq[] , int i , int j){
     int s= 0 ;
     for(int k=i;k<=j;k++){
         s += freq[k];
     }

     return s;
     // returning the sum
 }

int main(){
    int keys[] = {10,12,20};
    int freq[] = {34, 8,50};

    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<"Cost of Optimal BST is : "<<optimalSearchTree(keys , freq , n);

    cout<<"\n";

    return 0;
}