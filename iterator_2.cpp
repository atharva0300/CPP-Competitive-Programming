// iterator_2
#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>p;
	p = {1,2,3,4,5};
	cout<<"\nPrinting the vector : ";
	for(auto x: p)
		//auto keyword : automatically determines the data type 
	// and converts it to it 
	// and automatically appends itself in the loop
	// it creates a iterator , of  that data type 
	{
		cout<<x<<" ";
	}
	cout<<"\nUsing iterator to print vector : ";
	vector<int>::iterator pp;
	for(pp=p.begin();pp!=p.end();pp++)
	{
		cout<<*pp<<" ";
	}
	cout<<"\n";
	for(int value : p)
	{
		value++;
		// values insidet h p vecotr 
		// don't get changed 
		// it's bascically, changing the copy 
		// of the vector , and not the actual vector
	}
	cout<<"\n";
	for(int value : p)
	{
		cout<<value<<" ";
	}
	for(int &value : p)
	{
		// changes the actual values 
		// of the vector pair
		value++;
	}
	cout<<"\n";
	for(int value : p)
	{
		cout<<value<<" ";
	}
	vector<pair<int,int>>v = {{1,1} , {2,2} , {3,3}};
	cout<<"\nPrinting the pair : \n";
	for(auto x : v)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	// changing the value of the vector pair 
	for(auto &x : v)
	{
		x.second++;
	}
	cout<<"\nPrinting the vector pair after increasing the value : \n";
	for(auto x : v)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}