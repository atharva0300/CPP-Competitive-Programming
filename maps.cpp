// Maps 
// Unordered maps 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	// Map is like a dictionary ( in python )
	// A map stores the key , value pair 
	// example  - 1st data value is an 'int' , and the second 
	// data value is 'string'
	// then, 'map' will create a map of 'int' and 'string'
	// int 		string 
	// 1		Atharva
	// 2		Aditya
	// 3		Person
	
	// how do maps get stored ? 
	// every element of a map is a pair 
	// Unlike vector, where the elements get stored continuously
	// ( or sequentially ), in Map , the elements / values 
	// don't get stored continuously or sequentially.
	
	// Code 
	
	map<int,string>m;
	m[1] = "atharva";
	cout<<m[1]<<"\n";
	m[3] = "Aditya";
	m[2] = "Person";
	
	// another way to insert data in map 
	m.insert({4,"go"});
	
	// printing the map using iterator 
	// craete an iterator of map 
	map<int , string>::iterator it;
	for(it=m.begin() ; it!=m.end();it++)
	{
		//printing the pairs 
		// 1st way 
		cout<<(*it).first<<" "<<(*it).second<<"\n";
		
		//2nd way 
		cout<<it->first<<" "<<it->second<<"\n";
	}
	// Notice that the pairs  get printed , in the ascending order 
	// of the integer ( key value )
	// Therefore, maps maintain , the order ( ascending )
	
	// using auto , to print the map 
	cout<<"\nusing auto : \n";
	for(auto x: m)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	cout<<"\nChanging the value of the key in the map \n";
	for(auto &x: m)
	{
		//x.first = x.first+1;
	}
	cout<<"\nPritning the modified map : \n";
	for(auto x : m)
	{
		cout<<x.first<<"  "<<x.second<<"\n";
	}
	
	// Time complexity of inserting a value in the map is O(logn)
	// Example - time complexity of 
	// m[5] = "SRK"	  => O(logn)
	// m[2] = "hello"	=> O(logn)
	
	// Also the time complexity of accessing the value of the map 
	// is O(logn)
	// cout<<m[3];		=> O(logn)
	
	// map.finc(value);
	// this returns an iterator , of the value 
	// if the mao.find(value) dosen't find the value 
	// in the map , then map.end() iterator gets assigned 
	// to the iterator 
	
	// Example 
	cout<<"\nUsing the find : ";
	auto it2 = m.find(3);
	if(it2==m.end())
	{
		cout<<"NO element found\n";
	}
	else
	{
		cout<<(*it2).first<<" "<<(*it2).second<<"\n";
	}
	
	// erase 
	// map.erase ( value )
	// erases the key , value, matches the key, if found 
	// Exmaple 
	m.erase(3);	// time complexity => O(logn)
	cout<<"\nremoving key : 3 \n";
	cout<<"\nPritning the modified map : \n";
	for(auto x : m)
	{
		cout<<x.first<<"  "<<x.second<<"\n";
	}
	// erasing a value ( key ) that does not exist 
	m.erase(12);
	cout<<"\nerasing key : 12 \n";
	cout<<"\nPritning the modified map : \n";
	for(auto x : m)
	{
		cout<<x.first<<"  "<<x.second<<"\n";
	}
	// does nothing 
	
	// using iterator to erase
	/*
	auto it = m.find(7);
	m.erase(it);
	*/
	// gives segmentation fault 
	// becasue, the key : 7 does not exist 
	
	cout<<"\nFinding key 7 and erasing the key\n";
	cout<<"\nPritning the modified map : \n";
	
	// to avoid this, use a condition 
	auto it3 = m.find(7);
	if(it3!=m.end())
	{
		m.erase(it3);
	}
	cout<<"\ndone\n";
	
	// clearing the map 
	// map.clear()
	/*
			m.clear();
			cout<<"\nmap.clear() size : "<<m.size()<<"\n";
			cout<<"\nPritning the modified map : \n";
			for(auto x : m)
			{
				cout<<x.first<<"  "<<x.second<<"\n";
			}
	*/
	
	map<string , string>p;
	p["abcd"] = "abcd";
	// here the time complexity is not O(logn)
	// but 
	// string.size() * O(logn)
	// because, here the time for string comparison also gets added 
	// so the total time complexity is : time complexity to compare thr strings + time complexity of the map ( O(logn) )
	
	// Example 
	
	/*
	
		Question : 
		Given N strings,  print unique strings 
		in lexiographical order with their frequency 
		N <= 10^5
		|s| <= 100
		
		input : 
		8 
		abc 
		def
		abc
		ghj
		jkl
		ghj
		ghj
		abc
	
	*/
	/* 
	
		Answer below
	
	*/
	
	map<string, int>t;
	cout<<"\nQuestion input : ";
	int n;
	cin>>n;
	// taking input 
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		t[s] = t[s]+1;
		// when string, gets inputted first time 
		// ( when the frequency initially is 0 )
		// then t[s] gets automatically initialized to 0 
		 
	}
	//printing the map
	cout<<"\nPrinting the output : \n";
	for(auto x : t)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	// the keys ( string here ) gets automatically sorted in lexiographical order 
	// so, this 1st increases the frequency, then 2nd also prints the 
	// map in lexioggraphical order ( increasing / ascending order )
	
	
	
	
	
	
	
	
	cout<<"\n";
	system("pause");
	return 0;
}