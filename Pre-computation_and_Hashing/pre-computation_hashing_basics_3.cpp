// precomputation and hashing array 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int hsh[N];	
// global array's are always initialized to zero, 
// so no need to initialize them to zero 

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		hsh[arr[i]]++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		cout<<hsh[x]<<"\n";
	}
	cout<<"\n";
	// time complexity - O(N) + O(Q) = O(N) = or 2*10^5 < 1 second
	
	system("pause");
	return 0;
}