#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int>person;
	person.push_back(12);
	person.push_back(45);
	person.push_back(167);
	person.push_back(11);
	person.push_back(9);
	for(auto x : person)
	{
		cout<<x<<"\n";
	}
	cout<<person.front()<<"\n";
	cout<<person.back()<<"\n";
	if(person.front()>person.back())
	{
		cout<<person.front() - person.back()<<"\n";
	}
	else 
	{
		cout<<person.back() - person.front()<<"\n";
	}
	vector<int>person2(3 ,10);
	cout<<"\n";
	for(auto x : person2)
	{
		cout<<x<<"\n";
	}
	cout<<"\n";
	int arr[] ={10,20,30};
	int n = sizeof(arr) / sizeof(int);
	vector<int>person3(arr,  arr+n);
	for(auto x : person3)
	{
		cout<<x<<"\n";
	}
	cout<<"\n";
	vector<int>person4{1,2,3};
	vector<int>person5(person4.begin() , person4.end());
	for(auto x : person5)
	{
		cout<<x<<"\n";
	}
	
	// using fill - to fill the vector values 
	cout<<"\n";
	vector<int>person6(10);
	int number = 5;
	fill(person6.begin() , person6.end() , number);
	for(auto x : person6)
	{
		cout<<x<<"\n";
	}
	system("pause");
	return 0;
}