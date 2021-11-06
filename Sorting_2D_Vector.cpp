#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[] = {1,5,3,4,7};
	vector<int>person(arr  , arr + (sizeof(arr)/sizeof(int)));
	for(auto x : person)
	{
		cout<<x<<"\n";
	}
	sort(person.begin(), person.end());
	cout<<"\nSorted vector : \n";
	for(auto x : person)
	{
		cout<<x<<"\n";
	}
	
	// Displaying 2D VECTOR 
	cout<<"\nDisplaying 2D vector : \n";
	vector<vector<int>>person2{{1,2,3},
		{4,5,6},
			{7,8,9}};
	for(int i=0;i<person2.size();i++)
	{
		for(int j=0;j<person2[i].size();j++)
		{
			cout<<person2[i][j]<<" ";
		}
	}
	cout<<"\n";
	int m = person2.size() ;
	int o = person2[0].size();
	cout<<"The matrix before sorting 2st row : ";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<o;j++)
		{
			cout<<person2[i][j]<<" ";
			cout<<"\n";
		}
	}
	
	// using sort() inbuilt function to sort the 2d vector 
	sort(person2[0].begin() , person2[0].end());
	
	//displaying the 2d vector after sorting 
	cout<<"\nMatrix after sorting : \n";
	
	for(int i=0;i<person2.size();i++)
	{
		for(int j=0;j<person2[i].size();j++)
		{
			cout<<person2[i][j]<<" ";
		}
	}
	cout<<"\n";
	// sorting by first and second 
	// using vector pair 
	vector<pair<int , int>person3;
	
	int arr2[] = {1,2,5,4};
	int arr3[] = {3,6,2,5};
	

	
	system("pause");
	return 0;
}