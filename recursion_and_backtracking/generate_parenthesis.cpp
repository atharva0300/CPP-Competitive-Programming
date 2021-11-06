// Generate parenthesis 
#include<bits/stdc++.h>
using namespace std;

vector<string>valid;
void generate(string &s , int open , int close)
{
	if(open==0 && close==0)
	{
		valid.push_back(s);
		return;
	}
	if(open>0)
	{
		s.push_back('(');
		generate(s, open-1 , close);
		s.pop_back();
	}
	if(close > 0)
	{
		if(open<close)
		{
			s.push_back(')');
			generate(s,open ,close-1);
			s.pop_back();
		}
	}
}
int main()
{
	/* 
		Question : 
		
		Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

		Example 1:

		Input: n = 3
		Output: ["((()))","(()())","(())()","()(())","()()()"]
		Example 2:

		Input: n = 1
		Output: ["()"]
		 

		Constraints:

		1 <= n <= 8

	*/
	/* 
	
	2 conditions : 
	1. The opening bracket should be present ( open brackets > 0)
	2. While inserting a closing bracket, the number of opening and closing brackets should always be equal ( close brackets > 0 and open brackets > close brackets )
	*/
	int n;
	cin>>n;
	string s;
	generate(s,n,n);
	for(auto x : valid)
	{
		cout<<x<<"\n";
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}