// comparator_function_using C++_ sort 
#include<bits/stdc++.h>
using namespace std;

bool should_i_swap(int a,int b)
{
	if(a<b)
	// a<b - sorts in ascending order 
	// a>b - sorts in descending order 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool should_i_swap(pair<int , int>a, pair<int,int>b)
{
	if(a.first!=b.first)
	{
		if(a.first>b.first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(a.second < b.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(a<b)
	// a<b - sorts in ascending order 
	// a>b - sorts in descending order 
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	/* 
		input : 
		6
		7 3 5 9 10 2
	*/
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(should_i_swap(a[i], a[j]))
			{
			    swap(a[i] , a[j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	
	// Sorting vector pairs 
	
	/* 
		input : 
		6
		4 3
		5 5
		5 3
		25 6
		7 9
		8 5
		
		output : 
		4 3
		5 5
		7 9
		8 5
		25 6
	
	*/
	cout<<"\n";
	vector<pair<int , int>>b(n);
	for(int i=0;i<n;i++)
	{
		cin>>b[i].first>>b[i].second;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(should_i_swap(b[i], b[j]))
			{
			    swap(b[i] , b[j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<b[i].first<<" "<<b[i].second<<"\n";
	}
	cout<<"\n";
	system("pause");
	return 0;
}