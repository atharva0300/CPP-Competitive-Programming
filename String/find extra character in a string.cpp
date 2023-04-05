#include<bits/stdc++.h>
using namespace std;

char findExtraChar(string a,string b){
	// store string values in map
	unordered_map<char , int>m1;
	
	// store second string in map with frequency
	for(int i=0;i<b.length();i++){
		m1[b[i]]++;
	}
	
	// store first string in map with frequency 
	for(int i=0;i<a.length();i++){
		m1[a[i]]--;
	}
	
	for(auto h1=m1.begin();h1!=m1.end();h1++){
		// if the frequency is 1 then this 
		// character is which is added extra 
		if(h1->second==1){
			return h1->first;
		}
	}
}

int main(){
	string a,b;
	cout<<"\nEnter string a : ";
	cin>>a;
	cout<<"\nEnter string b : ";
	cin>>b;
	cout<<findExtraChar(a,b);
	
	cout<<"\n";
	system("pause");
	return 0;
}