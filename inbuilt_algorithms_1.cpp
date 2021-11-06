// Inbuilt algorithms - part 1 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	/* 
		input : 
		6
		2 3 1 6 7 6
	*/
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	
	// the minimum _element of a vector using STL
	auto it = min_element(v.begin()
 	, v.end());
	cout<<"\nMinimum element : "<<*it<<"\n"; 
	
	// similary the max element using STL
	auto it2 = max_element(v.begin() , v.end() );
	cout<<"\nMaximum element : "<<*it2<<"\n";
	
	auto it3 = max_element(v.begin()+3 , v.end() );
	cout<<"\nMaximum element : "<<*it3<<"\n";
	
	// Accumulate 
	// accumulate(start vector pointer , end vector pointer , starting sum )
	int sum = accumulate(v.begin() , v.end() , 0);
	cout<<"\nSum of the vector : "<<sum<<"\n";
	
	int sum2 = accumulate(v.begin() , v.end() , 5);
	cout<<"\nSum of the vector : "<<sum2<<"\n";
	
	// Count 
	// the count function returns the count of an element 
	// count(start vector address , end vector address , value);
	int ct = count (v.begin() , v.end() , 3);
	cout<<"\nCount of 3 in the vector : "<<ct<<"\n";
	
	int ct2 = count (v.begin() , v.end() , 6);
	cout<<"\nCount of 6 in the vector : "<<ct2<<"\n";
	
	// find function
	
	auto element = find(v.begin() , v.end() , 3);
	if(element!=v.end())
	{
		cout<<"\nFind 3 : "<<*element<<"\n";
	}
	else
	{
		cout<<"\Element not found";
	}
	
	auto element2 = find(v.begin() , v.end() , 20);
	if(element2!=v.end())
	{
		cout<<"\nFind 20 : "<<*element2<<"\n";
	}
	else
	{
		cout<<"\Element not found";
	}
	
	// reversing a vector usign STL
	reverse(v.begin() , v.end());
	cout<<"\nReverse vector : ";
	for(auto x : v)
	{
		cout<<x<<"\n";
	}
	
	// reversing a string 
	string s = "atharva";
	reverse(s.begin() ,s.end());
	cout<<"\nreverse string : "<<s<<"\n";
	
	string person = "adioo";
	reverse(s.beign()+1 , s.end());
	cout<<"\nReverse of string : "<<person<<"\n";
	
	
	// writing STL algorithms for array 
	int arr[n];
	for(int i=0;i<n;i++
	{
		cin>>arr[i];
	}
	int min2 =*min_element(arr , arr+n);
	cout<<"\nminimum : "<<min2<<"\n";
	
	int max10= *max_element(arr , arr+n);
	cout<<"\nMaximum : "<<max10<<"\n";
	cout<<"\n";
	system("pause");
	return 0;
}