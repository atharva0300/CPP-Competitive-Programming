// pre - sun of 2D array
#include<bits/stdc++.h>
using namespace std;

/* 
	Question : 
	Given 2d array a of N*N integers. Given Q queries and in each give a m b m c and d print sum of square represented by (a,b) as top left point and (c,d) as top bottom right point 

*/ 
/* 
	ConstraintS : 
	1 < = N <= 10^3
	1 < = a[i][j] <=10^9
	1 < = Q < = 10^5
	1 < = a,b,c,d < =N
*/

/*
	const int N = 1e3 + 10;
	int arr[N][N];

	int main()
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>arr[i][j];
			}
		}
		int q;
		cin>>q;
		while(q--)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			long long sum = 0;
			for(int i=a;i<=c;i++)
			{
				for(int j=b;j<=d;j++)
				{
					sum = sum + arr[i][j];
				}
			}
			cout<<sum<<"\n";
		}
		// TIme complexity - O(n^2) + O(Q*N^2) = 10^5 * 10^6 = 10^11 > 1 second 
		// not an acceptable solution
		
		cout<<"\n";
		system("pause");
		return 0;
	}
*/

const int N = 1e3 + 10;
int arr[N][N];
long long sum[N][N];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
			sum[i][j] = arr[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		cout<<sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1]<<"\n";
	}
	cout<<"\n";
	// time complexity - O(N^2) + O(Q) = 10^6 < 1 second 
	
	system("pause");
	return 0;
}

