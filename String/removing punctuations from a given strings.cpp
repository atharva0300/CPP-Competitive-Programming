#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string str = "This is %@ a per.son.& from the !divine";
	
	for(int i=0, len = str.size();i<len;i++){
		// check wheather parsing character is punctuation or not 
		if(ispunct(str[i])){
			str.erase(i-- , 1);
			len = str.size();
		}
	}
	
	// printing the string 
	cout<<"\nString without the punctuation marks : ";
	cout<<str<<"\n";
	
	cout<<"\n";
	system("pause");
	return 0;
}