// International Yoga day 

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll l,b;
	cin>>l>>b;
    ll n;
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll L,B;
		cin>>L>>B;
		ans =max((L/l)*(B/b) , (L/b)*(B/l));
	}
	cout<<ans<<"\n";
	system("pause");
	return 0;
}