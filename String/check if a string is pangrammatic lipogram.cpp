#include<bits/stdc++.h>
using namespace std;

/*
Lipogram: A lipogram is a kind of constrained writing or word game consisting of writing paragraphs or longer works in which a particular letter or group of letters is avoided—usually a common vowel, and frequently E, the most common letter in the English language. 
*/

string alphabets = "abcdefghijklmnopqrstuvwxyz";

// function to check for a pangrammatic lipgram
void panLipogramChecker(string s){
	// convert string to lower 
	for(int i=0;i<s.length();i++){
		s[i] = tolower(s[i]);
	}
	
	// variable to keep count of all the letters 
	// not found in the string 
	int counter = 0;
	
	// traverse the string for every 
	// letter of the alphabet
	for(int i=0;i<26;i++){
		int pos = s.find(alphabets[i]);
		
		// if character not found in string 
		// then increment count 
		if(pos<0 || pos>s.length()){
			counter += 1;
		}
	}
		
		if(counter==0){
			cout<<"Pangram : \n";
		}else if(counter>=2){
			cout<<"Not a pangram but might a lipogram\n";
		}else{
			cout<<"Pangrammatic Lipogram\n";
		}
}


int main(){
	
	string str = "The quick brown fox jumped over the lazy dog";
    panLipogramChecker(str);
     
    str = "The quick brown fox jumps over the lazy dog";
    panLipogramChecker(str);
     
    str = "The quick brown fox jum over the lazy dog";
    panLipogramChecker(str);
	cout<<"\n";
	system("pause");
	return 0;
}