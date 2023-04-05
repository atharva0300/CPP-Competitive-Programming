#include<bits/stdc++.h>
using namespace std;

bool isNumber(string s){
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])==false){
			return false;
		}
		return true;
	}
}
1
int main(){
	
	string str ;
	cout<<"\nEnter a string or a number : ";
	cin>>str;
	
	
	// function 
	if(isNumber(str)){
		cout<<"Integer\n";
	}else{
		cout<<"String\n";
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}