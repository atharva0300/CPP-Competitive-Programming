// nesting of maps and sets 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	map<int , int>m3;
	// key: int 
	// value : int
	
	// nested map 
	map<pair<int,int>,int>m2;
	// here the key of the map is the pair <int,int>
	// and the value is integer 
	
	//nesting pair, does not get stored in unordered map , because it uses has table 
	// but it gets stored in ordered_map
	
	pair<int,int>p1 , p2;
	p1 = {1,2};
	p2 = {2,3};
	cout<<(p1<p2)<<"\n";
	// here p1 pair is less than p2 pair 
	// because, the first of p1 is less than first of p2 
	
	// similarly to compare the second of p1 and second of p2
	cout<<(p1<p2)<<"\n";
	
	set<int>s1 = {1,2,3};
	set<int>s2 = {2,3,4};
	cout<<(s1<s2)<<"\n";
	// here s1 is less than s2 
	// because , the first element of s1 is less than first element of s2 
	
	//Note - comparison can be done in ordered _map but not in unordered map 
	
	map<pair<string, string>,vector<int>>m;
	// here the key is : pair<string, string> 
	// and the value si : vector<int>
	
	
	/* 
		input : 
		3
		a b 4
		1 2 3 4
		c d 2
		1 2
		d f 3
		2 3 4
	*/
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string f,l;
		int ct;
		cin>>fn>>ln>>ct;
		for(int j=0;j<ct;j++)
		{
			int x;
			cin>>x;
			m[{fn,ln}].push_back(x);
		}
	}
	// printing the value 
	for(auto &x : m)
	{
		auto &full_name = x.first;	// this is fn + ln
		auto &list = pr.second;	// this is the vector 
		cout<<full_name.first<<" "<<full_name.second<<" "<<list.size()<<"\n";
		for(auto &y : list)
		{
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	system("pause");
	return 0;
}