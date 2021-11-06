// multiset 
#include<bits/stdc++.h>
using namespace std;

void print(multiset<string>&s)
{
	for(auto x : s)
	{
		cout<<x<<"\n";
	}
}

int main()
{
	multiset<string>s;
	s.insert("abc");		// O (logn)
	s.insert("sdf");
	s.insert("fgh");
	s.insert("abc");
	s.insert("fgh");
	
	cout<<"\nPrinting the elements : \n";
	print(s);
	
	// using multiset.find(value)
	// finds the value and returns an iterator 
	auto it = s.find("abc");
	if(it!=s.end())
	{
		s.erase(it);
	}
	cout<<"\nPrinting the elements after erasing one value \n";
	print(s);
	// this deletes one value of 'abc' if multiple values 
	// are present 
	
	// to delete all the values 
	// use the below 
	s.erase("fgh");
	cout<<"\nPrinting the elements after erasing \"fgh\" value  :\n";
	print(s);
	cout<<"\n";
	system("pause");
	return 0;
}