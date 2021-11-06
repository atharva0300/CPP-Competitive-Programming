// Iterator
#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v  {1,2,3,6,7,8};
	cout<<"\nPrinting vector : ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	vector<int>::iterator it = v.begin();
	cout<<"\nPrinting iterator : ";
	for(int i=0;i<v.size();i++)
	{
		cout<<*(it)<<" ";
		it++;
	}
	
	// using iterators in pair 
	vector<pair<int,int>>p = {{1,2} , {2,3} , {3,4} ,{4,5}};
	vector<pair<int,int>>::iterator it2;
	cout<<"\nPriting vector pair iterator : \n";
	for(it2 = p.begin();it2!=p.end();it2++)
	{
		cout<<(*it2).first<<" "<<(*it2).second<<" "<<"\n";
	}
	// (*it).first <=> (it->first)
	// (*it).second <=> (it->second)
	cout<<"\n";
	system("pause");
	return 0;
}