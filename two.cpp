#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int shift;
    cin>>shift;
    for(int i=0;i<shift;i++){
        int start = arr[0];
        for(int j=0;j<n-1;j++){
            arr[j] = arr[j+1];
        }
        arr[n-1] = start;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    for(int i=0;i<shift;i++){
        int end= arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = end;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}