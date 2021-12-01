#include<bits/stdc++.h>
using namespace std;


/* 
Input  : arr[] = {1, 2, 3}
Output : 1

Input  : arr[] = {2, 4, 6, 8}
Output : 2
*/

/* 
    Formula : 

    gcd(a, b, c) = gcd(a, gcd(b, c)) 
                = gcd(gcd(a, b), c) 
                = gcd(gcd(a, c), b)
*/

/* 
For an array of elements, we do the following. We will also 
check for the result if the result at any step becomes 1 we will 
just return the 1 as gcd(1,x)=1. 

result = arr[0]
For i = 1 to n-1
result = GCD(result, arr[i])
*/

int gcd(int a , int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b , a%b);
    }
}

// Function to find the gcd of array of 
// numbers 
int findgcd(int arr[] , int n)
{
    int result = arr[0];
    for(int i=1;i<n;i++)
    {
        result = gcd(arr[i] , result);
        if(result==1)
        {
            return 1;
        }
    }
    return result;
    /* 
    Time Complexity: O(N * log(N)), where N is the largest element of the array
Auxiliary Space: O(1)
*/
}


// Using recursion 
int GcdOfArray(vector<int>& arr, int idx)
{
    if (idx == arr.size() - 1) {
        return arr[idx];
    }
    int a = arr[idx];
    int b = GcdOfArray(arr, idx + 1);
    return __gcd(a, b); // __gcd(a,b) is inbuilt library function

   /* 
    Time Complexity: O(N * log(N)), where N is the largest element of the array

    Auxiliary Space: O(N)
*/
}



// Driver code
int main()
{
    int arr[] = {2,4,6,8,16};
    int size = sizeof(arr)/sizeof(int);
    cout<<findgcd(arr ,size)<<"\n"; 

    // calling recursive function
    vector<int>arr2 = {2,4,6,8,16};
    cout<<GcdOfArray(arr2,0)<<"\n";
    return 0;
}