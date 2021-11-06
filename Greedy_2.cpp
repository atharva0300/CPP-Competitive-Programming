// Sell all the cars 
#include<bits/stdc++.h>
#define ll long long 
#define mod 1000000007
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>v;
		ll x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin() , v.end(),greater<int>());
		
		//starting selling 
		ll ans = 0;
		for(int i=0;i<n;i++)
		{
			ans = ans + max((ll)0,(v[i] - i));
			ans = ans%mod;
		}
		cout<<ans<<"\n";
	}
	system("pause");
	return 0;
}