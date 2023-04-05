#include<bits/stdc++.h>
using namespace std;

/*
New character set : qwertyuiopasdfghjklzxcvbnm
Input : "utta"
Output : geek

Input : "egrt"
Output : code
*/

/*
Given New character set = “qwertyuiopasdfghjklzxcvbnm” 

First character is q, during hashing we will place ‘a’ (for position ) at index q i.e. (17th).
After hashing our new character set is “kxvmcnophqrszyijadlegwbuft”.
For input “egrt” = 
  hash[e -‘a’] = c 
  hash[g -‘a’] = o 
  hash[r -‘a’] = d 
  hash[t -‘a’] = e
For “egrt” is equivalent to “code”.
*/

void conversion(char charSet[] , string &str ){
	int n = str.length();
	
	// hashing for new character set 
	char hashChar[26];
	for(int i=0;i<27;i++){
		hashChar[charSet[i]-'a'] = 'a' + i;
	}
	
	// conversion of new character set 
	for(int i=0;i<n;i++){
		str[i] = hashChar[str[i]-'a']; 
	}
}


int main(){
	char charSet[27] = "qwertyuiopasdfghjklzxcvbnm";
	string str;
	cout<<"\nEntera string : ";
	cin>>str;
	conversion(charSet,  str);
	cout<<str<<"\n";
	cout<<"\n";
	
	cout<<"\n";
	system("pause");
	return 0;
}