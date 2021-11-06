#include<bits/stdc++.h>

using namespace std;

int main()
{
	// Vector 
	vector<int>person;
	for(int i=0;i<=5;i++)
	{
		person.push_back(i);
	}
	cout<<"\nUsing begin and end : \n";
	// printing using begin() and end()
	for(auto i = person.begin();i!=person.end();i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\nReverse printing the vector : \n";
	// rbegin() and rend() and printing the vector 
	// using for loop reverses it 
	for(auto i=person.rbegin() ; i!=person.rend() ; i++)
	{
		cout<<*i<<" ";
	}
	cout<<"\nUsing crbegin and crend : \n";
	// crbegin()  - Returns a constant reverse iterator pointing 
	// to the last element in the vector ( reverse beginning )
	// It moves from last to first element 
	
	// crend() - Returns a constant reverse iterator pointing to the 
	// theoretical element preceding the first 
	// element in the vector ( considered as reverse end )
	for(auto i=person.crbegin();i!=person.crend() ; i++)
	{
		cout<<*i<<" ";
	}
	
	/*
	cbegin() – Returns a constant iterator pointing to the first element in the vector.
	cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	*/
	
	/*
	cbegin() – Returns a constant iterator pointing to the first element in the vector.
	cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	*/
	cout<<"\n";
	system("pause");
	return 0;
}