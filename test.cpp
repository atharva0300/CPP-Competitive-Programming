#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<string, int>t;
	int n;
	cin>>n;
	// getting the input values 
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		t[s]++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		cout<<t[s]<<"\n";
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}