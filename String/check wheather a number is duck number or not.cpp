#include<bits/stdc++.h>
using namespace std;

/*
A Duck number is a positive number which has zeroes present in it, For example 3210, 8050896, 70709 are all Duck numbers.
*/

bool duck(const string& str ){
	int n = str.length();
	for(int i=0;i<n;i++){
		if((int)str[i]==48){
			return true;
		}
	}
	return false;
}

int main(){
	string str;
	cout<<"\nEnter a number : ";
	cin>>str;
	if(duck(str)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}