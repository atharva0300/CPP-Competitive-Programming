// inbuilt STL algorithms and lambda function part 2 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	// lambda function
	// 
	/* 
	
		input : 
			6
			2 3 1 6 7 6
	*/
	
	/* 
		lambda function declaration : 
		[](int x){return x+2;}
		
		calling the function
		cout<<[](int x){return x+2;}{2}<<"\n";
		
		here 2 is the lambda input : x = 2
		
	*/
	cout<<[](int x){return x+2;}(2)<<"\n";
	// prints 4 as x+2 = 4 when x=2;
	
	cout<<[](int x , int y){return x+y;}(2,3)<<"\n";
	
	// assigning to a variable to use the function miltiple times 
	
	auto sum = [](int x){return x+4;};
	cout<<sum(6)<<"\n";
	cout<<sum(12)<<"\n";
	auto sum2 = [](int x,int y){return x*y;};
	cout<<sum2(2,3)<<"\n";
	
	// using vector 
	cout<<"\nall of : \n";
	vector<int>v = {2,3,5};
	cout<<"\n";
	// all_of(start vector address , end vector address,  element)
	// uses the cndition all of 
	cout<<all_of(v.begin() , v.end() , [](int x){return x>0;});
	// if the all_of() function os true , then, the all_of) function returns 1 
	// else, if false, returns 0
	cout<<"\n";
	
	cout<<all_of(v.begin() , v.end() , [](int x){return x>3;});
	
	cout<<"\n";
	cout<<all_of(v.begin() , v.end() , [](int x){return x>0;});
	
	// any_of function() 
	cout<<"\nany of : \n";
	cout<<any_of(v.begin() , v.end() , [](int x){return x>3;});
	// of any of the element is greater than 3 
	// then the outcome is true , 1
	// else, 0
	cout<<"\n";
	cout<<any_of(v.begin() , v.end() , [](int x){return x<0;});
	
	cout<<"\nnone of :\n";
	cout<<none_of(v.begin() , v.end() , [](int x){return x>3;});
	// prints true ( 1 ) only if none of the element 
	// is satisfied
	// else false ( 0 )
	// or - if the and of all the condition os true, then returns false 
	// else true 
	cout<<"\n";
	cout<<any_of(v.begin() , v.end() , [](int x){return x<0;});
	
	cout<<"\n";
	cout<<any_of(v.begin() , v.end() , [](int x){return x>0;});
	
	
	
	
	
	cout<<"\n";
	system("pause");
	return 0;
	//return 0;
}