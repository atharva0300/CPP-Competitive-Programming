#include<bits/stdc++.h>
using namespace std;


/* 
Input : {1, 2, 8, 3}
Output : 24

Input : {2, 7, 3, 9, 4}
Output : 252
*/

/* 
    lcm (a,b) = a*b/(gcd(a,b))
*/
/* 
lcm (a,b,c) != a*b*c/(gcd(a,b,c))
*/

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else{
        return gcd(b ,a%b);
    }
}

long long lcm(int arr[] , int n)
{
    // Initialize result 
    long long ans = arr[0];

    // ans contains lcm of arr[0] , .... arr[i]
    // after ith iteration 
    for(int i=0;i<n;i++)
    {
        ans = ((ans * arr[i])/gcd(ans ,arr[i]));
    }
    return ans;
}


// Using recursion 
int lcm2(int arr[] ,int n , int i , int ans)
{
    if(i==n)
    {
        return ans;
    }
    else
    {
        return lcm2(arr , n , i+1 , (ans*arr[i])/gcd(ans,arr[i]));
    }  
}

int main()
{
    int arr[3] = {2,3,4};
    cout<<lcm(arr , 3)<<"\n";

    // using recursion 
    cout<<lcm2(arr , 3 , 0 , arr[0])<<"\n";
    return 0;
}