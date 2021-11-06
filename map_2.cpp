// Maps  
// Unordered maps 
// Ordered maps 

// Difference in ordered and unrdered map 
// 1. unbuilt implementation
// 2. Time complexity of both of them is different 
// 3. valid key data type 
// 4. Order is maintained in ordered map, but not in unordered map 
// 5. Ordered map uses tree , unordered map uses hash table

// in unordered_map , a hash value is calculated of every key 

// Average time complexity of accessing a value in unordered map = O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<int , string>m;
	m[1] = "a";
	m[2] = "b";
	m[3] = "c";
	m[5] = "t";
	m[4] = "r";
	for(auto x  :m)
	{
		cout<<x.first<<" "<<x.second<<"\n";
	}
	// printing using iterator 
	unordered_map<int , string>::iterator it;
	cout<<"\nPrinting using iterator : \n";
	for(it=m.begin() ; it!=m.end() ; it++){
		cout<<it->first<<" "<<it->second<<"\n";
	}
	
	// using pair in unordered_map
	//unordered_map<pair<int , int> , string>p;
	
	// the insertion in the unordered_map uses hash value, 
	// so here , the hash value of hte pair will be used 
	// but a pair does not have a hash function defined ( inbuilt) 
	// in ordered_map you can directly inset a pair in the map 
	// in unordered_map, this is not the case, as it uses hash_table 
	
	// wherewere the comparison is possible, then you can inset a pair 
	
	/* 
		Question : 
		Given N strings and Q queries.
		In earth query and you are given a string
		print the frequency of that string
	
		N <= 10^6
		|s| <=100
		Q <= 10^6
		
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
		2
		abc
		ghj
		
		output :
		3
		3
	
	*/
	
	/* Solution	*/ 
	unordered_map<string, int>t;
	int n;
	cin>>n;
	// getting the input values 
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		t[s]++;
	}
	int q;
	cin>>q;
	while(q--)
	{
		string s;
		cin>>s;
		cout<<t[s]<<"\n";
	}
	
	// Multimap 
	// Difference in map and multimap
	// 1. implementation similar to red-black tree
	// 2. in map, there are unique keys
	// in multimap, the keys get used 2 times 
	
	map<int , vector<string>>r;
	
	cout<<"\n";
	system("pause");
	return 0;
}