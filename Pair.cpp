#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	// A pair is a container which stores data of different data 
	// types together 
	// like in the below example , the container stores 
	// 2 different data types- int and char 
	// acccess by using first and second 
	
	pair<int ,char>person;
	person.first = 12;
	person.second = 'A';
	cout<<"\nperson.first : "<<person.first;
	cout<<"\nperson.second : "<<person.second;
	
	pair<string , char> person2;
	cout<<"\nperson 2 : "<<person2.first;
	cout<<"\nperson 2 : "<<person2.second;
	
	// make_pair()
	pair<string , double> person3("atharva" , 12.3);
	cout<<"\nperson 3 : "<<person3.first;
	cout<<"\nperson 3 : "<<person3.second;
	
	pair<string , double>person4;
	person4 = make_pair("aditya" , 12.3);
	cout<<"\nperson 4 : "<<person4.first;
	cout<<"\nperson 4 : "<<person4.second;
	
	pair<string , double>person5("atharva" , 12.3);
	//using operators 
	if(person3==person4)
	{
		cout<<"\nThey are the same";
	}
	else 
	{
		cout<<"\nThey are not the same";
	}
	
	if(person3==person5)
	{
		cout<<"\nThey are the same";
	}
	else 
	{
		cout<<"\nThey are not the same";
	}
	pair<char ,int>personn5 = make_pair('A' , 123);
	cout<<"\nperson 5 : "<<person5.first;
	cout<<"\nperson 5 : "<<person5.second;
	
	cout<<"\nBefore swapping : \n";
	person5.swap(person4);
	cout<<"\nperson 4 : "<<person4.first;
	cout<<"\nperson 4 : "<<person4.second;
	cout<<"\nperson 5 : "<<person5.first;
	cout<<"\nperson 5 : "<<person5.second;
	// swapping 
	cout<<"\nAfter swapping : \n";
	person5.swap(person4);
	cout<<"\nperson 4 : "<<person4.first;
	cout<<"\nperson 4 : "<<person4.second;
	cout<<"\nperson 5 : "<<person5.first;
	cout<<"\nperson 5 : "<<person5.second;
	
	//tie 
	pair<int , int>person6 = {12.3 , 6.0};
	int a,b;
	tie(a,b) = person6;
	cout<<"\na : "<<a;
	cout<<"\nb : "<<b;
	
	pair<int , int>person7 = {3,4};
	tie(a,ignore ) = person7;
	cout<<"\na : "<<a;
	cout<<"\nb : "<<b;
	
	pair<int, pair<int ,char>>person7 = {3 , {4,'a'}};
	int x , y;
	char z;
	
	x = person6.first;
	tie(y ,z) = person6.second;
	cout<<"\nx : "<<x;
	cout<<"\ny : "<<y;
	cout<<"\nz : "<<z;
	
	cout<<"\n";
	system("pause");
	return 0;
}