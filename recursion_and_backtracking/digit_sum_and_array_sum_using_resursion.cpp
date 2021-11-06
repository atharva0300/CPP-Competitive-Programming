// digit sum and array sum using recursion 
#include<bits/stdc++.h>
using namespace std;

// Sum of array 
// Sum (n,a)
// Sum(n,a) = a[n] + sum(n-1,a)

int sum(int n , int a[])
{
	if(n<0)
	{
		return 0;
	}
	else
	{
		return sum(n-1 , a) + a[n];
	}
}
int main()
{
	int n;
	cin>>n;
	// input 
	int arr[n];
	/* 
		input : 
		6
		1 2 3 4 5 6
		
	*/
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<sum(2 , arr)<<"\n";
	cout<<sum(4,arr)<<"\n";
	cout<<sum(sizeof(arr)/sizeof(int) , arr)<<"\n";
	system("pause");
	return 0;
}