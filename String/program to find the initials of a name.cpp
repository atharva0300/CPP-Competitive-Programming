#include<bits/stdc++.h>
using namespace std;

void printInitials(const string& name){
	if(name.length()==0){
		return;
	}
	
	cout<<"\nname length : "<<name.length()<<"\n";
	// since, toupper() returns int, we type cast it into charcter
	cout<<(char)toupper(name[0])<<" ";
	
	// traversig the entire list 
	// and printing the characters after space 
	for(int i=1;i<name.length()-1;i++){
		if(name[i]==' '){
			cout<<(char)toupper(name[i+1])<<" ";
		}
	}
}

int main(){
	string str;
	cout<<"\nEnter a stirng : ";
	getline(cin , str);
	printInitials(str);
	
	cout<<"\n";
	system("pause");
	return 0;
}
/*
// C++ program to print initials of a name
#include <bits/stdc++.h>
using namespace std;
 
void printInitials(const string& name)
{
    if (name.length() == 0)
        return;
 
    // Since toupper() returns int, we do typecasting
    cout << (char)toupper(name[0]);
 
    // Traverse rest of the string and print the
    // characters after spaces.
    for (int i = 1; i < name.length() - 1; i++)
        if (name[i] == ' ')
            cout << " " << (char)toupper(name[i + 1]);
}
 
// Driver code
int main()
{
    string name = "prabhat kumar singh";
    printInitials(name);
    
	cout<<"\n";
	system("pause");
	return 0;
}
*/