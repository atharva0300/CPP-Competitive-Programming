// pre-computationn and hashing basics _ 2 
#include<bits/stdc++.h>
using namespace std;

/*
	Question : 
	Given array a of N integers. Given Q queies and in each query given a number X , print coutn of that number in array 
	
	Constraints : 
	1 < = N < = 10^5
	1 < = a[i] < = 10^7
	1 < = Q < = 10^5
*/

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		int ct = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==x)
			{
				ct++;
			}
		}
		cout<<ct<<"\n";
	}
	
	// time complexity - O(N) + ( input array )
	//					+ O(N+Q) ( quries and n)
	/*
		so the total time complexity is - O(N) + O(N*Q)
							  = 10^10 > 1 second 
	*/
	
	cout<<"\n";
	system("pause");
	return 0;
}