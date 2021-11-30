#include<bits/stdc++.h>
using namespace std;


/* 
For example: Say  = "hacker" and . Here .
Shifting each character in  by  positions to the right would result into . 'erhack'

*/

string shiftByK(char s[] , char shiftedS[] , int n ,int k)
{
    // iteratie through the length of the given string 
    for(int i=0;i<n;i++)
    {
        // Find the index for this current character is shiftedS[]
        int idx = (i+k)%n;
        // copy that character at the found idex idx 
        shiftedS[idx] = s[i];
    }
    // Add a ULL character to mark the end of the string 
    shiftedS[n] = '\0';
    return shiftedS;
}


int main()
{
    
    return 0;
}