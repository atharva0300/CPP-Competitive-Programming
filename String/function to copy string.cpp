// Iterative CPP Program to copy one String 
// to another.
#include <bits/stdc++.h>
using namespace std;
 
// Function to copy one string to other
// assuming that other string has enough
// space.
void myCopy(char s1[], char s2[])
{
    int i = 0;
    for (i=0; s1[i] != '\0'; i++)
       s2[i] = s1[i];
    s2[i] = '\0';
}
 
 
 // function to copy one string in to other 
 // using recursion 
 void myCopy2(char s1[] , char s2[] , int index=0){
	 // copying each character from s1 to s2
	 s2[index] = s1[index];
	 
	 // if string reach to end then stop 
	 if(s1[index]=='\0'){
		return;
	 }
	 
	 // increase character index by one 
	 myCopy2(s1 , s2 , index+1);
	 
 }
// Driver function
int main()
{
    char s1[100] = "atharvapingale";
    char s2[100] = "";
    myCopy(s1, s2);
    cout << s2<<"\n";
	char s3[100] = "";
	myCopy(s1,s3);
	cout<<s3<<"\n";
	cout<<"\n";
	system("pause");
    return 0;
}