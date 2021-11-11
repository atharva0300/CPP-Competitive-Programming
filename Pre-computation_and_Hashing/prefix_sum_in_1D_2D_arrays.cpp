// prefic sum in 1D and 2D array 
#include<bits/stdc++.h>
using namespace std;

/* 
	Question  :
	Given array a of N integers. Given Q queries and in each query 
	L and R print sum of array elements from index l to R ( L,R included )
	
	Constraints : 
	1 < = N <= 10^5
	1 <= a[i] < =10^9
	1 < = Q < = 10^5
	1 <= L , R <=N
*/ 



/*
	const int N = 1e5 + 10;
	int arr[N];

	int main()
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int q;
		cin>>q;
		while(q--)
		{
			int l ,r;
			cin>>l>>r;
			long long sum = 0;
			for(int i=l;i<r;i++)
			{
				sum = sum + arr[i];
			}
			cout<<sum<<"\n";
		}
		cout<<"\n";
		
		// time complexity -  O(N) + O(Q*N) = O(N^2) = 10^10 ~ 1 second 
		// too long 
		// solution below 
		
		system("pause");
		return 0;
	}
*/

const int N = 1e5+7;
int sum[N];
// already initialized to 0 by default ( since it is a global array )

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		sum[i]= sum[i-1] + arr[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<"\n";
	}
	cout<<"\n";
	system("pause");
	return 0;
}

