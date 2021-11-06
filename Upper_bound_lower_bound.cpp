// Upper bound and lower bound 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	/* 
		input : 
		6 
		4 5 5 25 7 8
	*/
	/* 
		lower bound : only works for sorted array s 
		lower vond finds the element , if the element is present 
		int the array then it finds that element, else it finds 
		the element that is greater than that element.
		example - lower bound of 7 : 7 
				lower bound of 6 : 7
		
		example : sorted array : 4 5 5 7 8 25
					lower bound of 5 : 5 ( 5 is present )
					lower bound of 7 : 7 ( 7 is present )
					lower bound of 6 : 7  ( 6 does not exist,the greater element. ie - 7)
					lower bound of 26 : gives the next pointer of the last element ( because a number greater than 26 does not exist) 
		
		
		upper bound of 5 : 7
		upper bound of 7 : 8
		upper bound of 6 : 7 ( even if the number 6 does not exist in the array )
		upper bound of 8 : 25 
		
	*/
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a , a+n);
	cout<<"\nPrinting the array : \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\n";
	}
	
	// creating a pointer 
	// lower_bound(starting address , end address, the element of which you want ot find the lower bound of  )
	int *ptr = lower_bound(a ,a+n ,5);
	cout<<"\nLower bound of 5 : ";
	cout<<*ptr<<"\n";
	int *ptr2 = lower_bound(a,a+n,26);
	if(ptr2==(a+n))
	{
		cout<<"\nNot found";
	}

	// upper bound 
	// upper_bound(starting address,  end address , the element of which you want to find the upper bound of )
	int* ptr3 = upper_bound(a,a+n,5);
	cout<<"\nUpepr bound of 5 : "<<*ptr<<"\n";
	int *ptr4 = upper_bound(a,a+n,26);
	if(ptr4==(a+n))
	{
		cout<<"\nNot found";
	}
	cout<<"\nupper bound of 26 : "<<*ptr4<<"\n";
	
	int *ptr5 = upper_bound(a+4,a+n,8);
	if(ptr5==(a+n))
	{
		cout<<"\nNot found";
	}
	cout<<"\nupper bound of 8 : "<<*ptr5<<"\n";
	
	// Similarly for vector 
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin() , v.end());
	auto it = upper_bound(v.begin()  ,v.end() , 5);
	if(it==v.end())
	{
		cout<<"\nNot found";
	}
	cout<<"\nit upper bound 5 : "<<*it<<"\n";
	
	// Upper boudn and lower bound in maps and sets 
	set<int>s;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		s.insert(x);
	}
	
	auto it2 = s.lower_bound(5);
	// don't use
	// auto it2 = lower_bound(s.begin() , s.end() , value);
	// this is because, it gives tou time limit error 
	// because, the time complexity of the lower_bound 
	// function is not n*log(n) but O(n).
	// so pputting a random value of say 10^5, icreases 
	// the rutime, and gives TLE
	// instead use the below 
	// auto it2 = s.lower_bound(value);
	// this is faster than the above.
	
	cout<<"\nset lower bound of 5 : "<<*it2<<"\n";
	
	// Similarly for maps 
	map<int ,int >m;
	for(int i=0;i<n;i++)
	{
		cin>>m[i].first>>m[i].second;
	}
	
	cout<<"\n";
	system("pause");
	return 0;
}