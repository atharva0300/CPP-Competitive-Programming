// Inbuilt sorting algorithm _ introsort 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a , a+n);
	// in sort() function 
	// 2 addresses are passeed 
	// the start address ( here - a  ) , not that it is not &a
	// because the address of the array , is just the array name ( starting addresss of the array )
	// the end address of the array is the array_name + size_of_array
	// not that, we don't pass a + n-1 ,  becaus , it requires the 
	// address of the next element of the last element of the array 
	// it is bascically a pointer, which stops iterating 
	// when, the sort() function, reache the next address of the last address 
	
	// printin the array 
	cout<<"\nPrinting the array : \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\n";
	}
	
	// sorting vector 
	vector<int>b(n);
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(b.begin() , b.end());
	// here , b.begin() isa  pointer that points to the address 
	// of the first element 
	// the b.end() pointer is a poitner, that points to the address 
	// of the next of the last element
	cout<<"\nb.end() : ";
	cout<<*b.end()<<"\n";
	cout<<"\nb.end() - 1 : ";
	cout<<*(b.end()-1)<<"\n";
	cout<<"\n";
	system("pause");
	return 0;
}