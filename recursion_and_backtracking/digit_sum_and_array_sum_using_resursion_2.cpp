// Digit sum 
#include<bits/stdc++.h>
using namespace std;

int digit_sum(int n)
{
	if(n==0)
	{
		return 0;
	}
	return digit_sum(n/10) + (n%10);
}
int main()
{
	int n;
	cin>>n;
	cout<<digit_sum(n)<<"\n";
	
	// 1. Number of function calls -> number of digits in the number 
	// 2. What id the complexity og each function call -> O(1)
	// total complexity here - log(n)
	system("pause");
	return 0;
}