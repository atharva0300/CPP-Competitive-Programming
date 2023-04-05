#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;


string missingChars(string str){
	// a boolean array to store characters 
	// persent in string 
	
	bool present[MAX_CHAR] = {false};
	
	//traverse strin and mark characters
	// present in string 
	
	for(int i=0;i<str.length();i++){
		if(str[i]>='a' && str[i]<='z'){
			present[str[i]-'a'] = true;
		}else if(str[i]>='A' && str[i]<='Z'){
			present[str[i]-'A'] = true;
		}
	}
	
	// store missing characters in alphabetic 
	// order 
	string res = "";
	for(int i=0;i<MAX_CHAR;i++){
		if(present[i] == false){
			res.push_back((char)(i+'a'));
		}
	}
	
	return res;
}

int main(){
	string str = "The quick brown for jumps over the dog";
	cout<<missingChars(str)<<"\n";
	
	string str2;
	cout<<"\nEnter a string : ";
	cin>>str2;
	cout<<missingChars(str2)<<"\n";
	
	system("pause");
	return 0;
}