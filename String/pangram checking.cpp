#include<bits/stdc++.h>
using namespace std;

/*
Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.
Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’] 
“The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contain all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]
*/

bool checkPangram(string &str){
	
	// create a hash table to mark the charactes 
	// present in the string 
	vector<bool>mark(20 , false);
	
	// for indexing in mark[]
	int index;
	
	// teaersing all the characters 
	for(int i=0;i<str.length();i++){
		
		// if uppercase character, subtract 'A'
		// to find index 
		if('A'<=str[i] && str[i]<='Z'){
			index = str[i] = 'A';
		}
		// if lowercase character, subtract 'a'
		// to find index 
		else if('a'<=str[i] && str[i]<='z'){
			index = str[i] -'a';
		}
		
		else{
			continue;
		}
		
		mark[index] = true;
	}
	
	// return false if any character is inmarked 
	for(int i=0;i<=25;i++){
		if(mark[i] ==false){
			return (false);
		}
	}
	
	// if all characters were present 
	return true;
}

int main(){
	string str = "The quick brown fox jumps over the lazy dog";
	
	if(checkPangram(str)==true){
		cout<<"pangram : "<<str.c_str()<<"\n";
	}else{
		cout<<"not a pangram : "<<str.c_str()<<"\n";
	}
	cout<<"\n";
	
	system("pause");
	return 0;
}