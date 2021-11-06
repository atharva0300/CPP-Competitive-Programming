// recursion 
#include<bits/stdc++.h>
using namespace std;

void func(int n)
{
	if(n==0)
	{
		return;
	}
	else
	{
		cout<<n<<"\n";
		func(n-1);
	}
}

int fact(int n)
{
	if(n==1){
		
		return 1;
	}
	else 
	{
		return n*fact(n-1);
	}
}
int main()
{
	// What is recursion ?
	/* 
		a function that calls itself is called recursion 
	*/
	/*
		when a function calls itself, then it will happen
		that the loop will be called infinite times 
		TO , stop that - 
		we will use a condition and return 
	*/
	
	/* 
		the recursion calls in recursion happens like a stack 	
		calling order : 
		func1() -> func2() -> func3() -> func4() 
		
		funcally the command will be inside the func4 
		first the address of func1() will be stored and then,
		the address of func2() will be called 
		then the func3() and func4() .
		when, the loop runs infinite itmes, 
		then the error arises called as : SEGMENTATION FAULT 
		which means that , the THE  STACK IS GETTING OVERFLOWED 
		
		printing / executing order : 
		Base conditin is satisfied , return at func4() is called 
		func4() -> func3() -> func2() ->func1() 
	*/
	
	func(5);
	// prints 5 4 3 2 1
	/*
		the printing starts , from the end ( ie - the elemets get 
		printed in decreasing order )
	*/
	cout<<"\nfactorial of 5 : "<<fact(5)<<"\n";
	
	// 1. Number of  function calls -> O(n)
	// 2. What is the complexity of each function -> O(1)
	// Total Time complexity here : O(n^2)
	
	system("pause");
	return 0;
}