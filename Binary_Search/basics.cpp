// Binary search basics 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*
		Linear search : 1 2 3 4 5 6 - time complexity -  O(n)
		
		Monotonic functions : The functions which maintain a given order 
		Example - 1 2 3 4 5 6  (increasing order )
				- 1 3 4 5 6 ( increasing order )
		
				- 1 3 2 5	( not an increasing order , not monotonic )
		Binary search can only be applied on monotonic functions 
		
	*/
	/* 
		example , y = x graph, as x increases, y also increases 
		
		can also apply on predicte functions, 
		suppose a function, returns  - F F F F T T T T .. ( T times infinity )
			or 
			T T T T F F F F .. ( F times infinity)
			F F T T F F .. ( not monotonic )
	*/
	/* 
		Example - array - 2 3 4 5 6 7
				  index - 0 1 2 3 4 5
			Search 5 
			
			Procudure : 
			1. Go to the middle page 
			2. if the number there is greater than, the middle element, then we move forward ( search ahead ) 
			3. else, we search below ( search behind the middle page / index )
			
		
		search space -> 0 -> 5  ( index )
		mid		|	search space -> 0 - 5
		-----------------------
		2			-> 3 - 5
		4			-> 3 - 3
		3 			-> 5
		
		Execution : 
		1. 4 is the middle element 
		2. 4 !=5 , but 5 is greater than 4 
		3. so, we will search ahead ( forward / right side )
		4. the middle element in the range ( 4 - 7 ) , is 5 
		5. now, the middle element == 5 
		6. hence we found our element 
		
		so, we got our element in 5 searches 
	*/
	
	
	/* 
		Code 
	*/
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int to_find;
	cin>>to_find;
	int low = 0;
	int high = n-1;
	int mid;
	
	while(high-low>1)
	{
		int mid = (high+low)/2;
		// to see if the middle element is greater or less than to_find
		if(arr[mid]<to_find)
		{
			low= mid +1;
		}
		else
		{
			high = mid;
		}
	}
	if(arr[low]==to_find)
	{
		cout<<"\nElement found at index : "<<low<<"\n";
	}
	else if(arr[high]==to_find)
	{
		cout<<"\nElement found at index : "<<high<<"\n";
	}
	
	cout<<"\n";
	system("pause");

	return 0;
}