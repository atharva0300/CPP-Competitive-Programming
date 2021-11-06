// set , unordered_map , multiset 
#include<bits/stdc++.h>
using namespace std;

void print(set<int>&s)
{
	for(int value : s)
	{
		cout<<value<<"\n";
	}

}
void print2(set<string>&s2)
{
	for(string value : s2)
	{
		cout<<value<<"\n";
	}
}

int main()
{
	// Sets 
	// sets - a set of keys, ( or a unique set of numbers )
	// collection of some elements is called sets 
	// sets are similr to maps in this aspect
	
	set<int>s;
	set<string>s2;
	// set - stores the element in sorted order 
	
	s.insert(12);
	s2.insert("abc");
	s.insert(13);
	s2.insert("ghj");
	s.insert(12);
	s2.insert("abc");
	// time complexity of insertion in a set - O(logn)
	
	// time complexity of asseccing in a set - O(logn)
	
	// s.find(value ) - returns the iterator, if the value is found in the set  
	auto it  =s.find(12);
	// as a precaution use condition 
	if(it!=s.end())
	{
		cout<<(*it);
		cout<<"\n";
	}
	// printing the found, element using iterator 
	cout<<"\nPrinting values : \n";
	print(s);
	print2(s2);
	
	// set.erase(value) 
	auto it2 = s.find(13);		// Time complexity - O(logn)
	if(it2!=s.end())
	{
		s.erase(*it2);
	}
	cout<<"\nprinting the set after erasing \n";
	print(s);
	
	
	// unordered_set 
	// stores unordered unique elements
	// time complexety of insertion - O(1)
	// tie complexity of finding a value - O(1)
	
	unordered_set<string>m;
	m.insert("a");		// O(1)
	m.insert("m");
	m.insert("b");
	m.insert("z");
	
	// using iterator to print the elements 
	cout<<"\nPrinting the unordered_set \n";
	unordered_set<string>::iterator it3;
	for(it3=m.begin();it3!=m.end();it3++)
	{
		cout<<*it3<<"\n";
	}
	cout<<"\n";
	auto it4 = m.find("b");		// O(1)
	if(it4!=m.end())
	{
		m.erase(*it4);
	}
	cout<<"\nPrinting value after erasing \n";
	for(it3=m.begin();it3!=m.end();it3++)
	{
		cout<<*it3<<"\n";
	}
	
	/* 
		Question : 
		Given N strings and Q queries.
		In each query you are given a string 
		print yes if string is present 
		else print number.
		
		N <= 10^6
		|s| <=100
		Q <= 10^6
	
	*/
	
	unordered_set<string>p;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		p.insert(s);
	}
	// finding the element 
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		string s;
		cin>>s;
		auto it = p.find(s);
		if(it!=p.end())
		{
			p.erase(it);
			cout<<"yes\n";
		}
	}
	
	
	cout<<"\n";
	system("pause");
	return 0;
}