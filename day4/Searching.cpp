#include<bits/stdc++.h>

using namespace std;


void display(int arr[] , int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	
	int arr[] = {1,7,2,5,7,9,5,4,7,10};
	int size = sizeof(arr)/sizeof(int);
	cout<<"\nOriginal array : ";
	display(arr,  size);
	cout<<"\nEnter an element to search : ";
	int element;
	cin>>element;
	if(binary_search(arr , arr+size ,element))
	{
		cout<<"\nElement found in the array ";
	}
	else 
	{
		cout<<"\nElement not found in the array ";
	}
	cout<<"\n";
	system("pause");
	return 0;
}