#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int half = floor(sum/2);
    // finding the subarray, that is closest to the half ( combined sum is closest to the half variable number );
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            
        }
    }
    
}