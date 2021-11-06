// Balanced brackets matching stack 
#include<bits/stdc++.h>
using namespace std;

// using unordered map 
unordered_map<char, int>symbols ={{'[' , -1} , {'(' , -2},{'{' , -3} ,{']' ,1} , {')' , 2} , {'}' , 3}};
string isBalanced(string s)
{
	stack<char>st;
	for(char bracket: s)
	{
		if(symbols[bracket]<0)
		{
			st.push(bracket);
		}
		else
		{
			if(st.empty())
			{
				return "NO";
			}
			else
			{
				char top = st.top();
				st.pop();
				if(symbols[top] + symbols[bracket]!=0)
				{
					return "NO";
				}
			}
		}
	}
	if(st.empty())
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
	
}

int main()
{
	// What is balanced brackets matching ? 
	
	/* 
		to know if all the brackets are openend and closed 
		example - (  ( ( )))	- balanced 
					( ( )		- unbalanced 
	
	*/
	
	/* 
		Question link - 
		https://www.hackerrank.com/challenges/balanced-brackets/problem
		
		input : 
		3
		{[()]}
		{[(])}
		{{[[(())]]}}
		
		output : 
		YES
		NO
		YES
	
	*/
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<isBalanced(s)<<"\n";
	}
	
	system("pause");
	return 0;
}