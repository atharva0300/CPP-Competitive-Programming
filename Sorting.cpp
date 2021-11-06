#include<bits/stdc++.h>

using namespace std;

void show(int a[] , int array_size )
{
	for(int i=0;i<array_size;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[] = {1,5,2,3,4,8,6,9};
	
	int size = sizeof(a)/sizeof(int);
	cout<<"\nOriginal array : ";
	show(a, size);
	sort(a , a+ size );
	cout<<"\nShowing the sorted array : ";
	show(a , size);
	
	cout<<"\n";
	system("pause");
	return 0;
}