#include<bits/stdc++.h>
using namespace std;


bool allCharacterSame(string str){
	int n = str.length();
	for(int i=1;i<n;i++){
		if(str[i]!=str[i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	
	string str;
	cout<<"\nEnter a string : ";
	cin>>str;
	if(allCharacterSame(str)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	
	// using set
	set<char>temp;
	for(int i=0;i<str.length();i++){
		temp.insert(str[i]);
	}
	// if all characters are same 
	// size of set will always be 1
	
	if(temp.size()==1){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	
	// time complexity => O(nlogn)
	
	cout<<"\n";
	system("pause");
	return 0;
}