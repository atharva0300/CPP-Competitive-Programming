#include<bits/stdc++.h>

using namespace std;

int main()
{
	pair<string , int>person8;
	pair<string , int>person9("person9" ,657);
	pair<string , int>person10(person9);
	pair<int , int>person11(123,456);
	
	person8 = make_pair(string("person8") , 1);
	person9.first = "modified value";
	person9.second = 90;
	
	cout<<"\nperson 8 : "<<person8.first;
	cout<<"\nperson 8 : "<<person8.second;
	
	cout<<"\nperson10 : "<<person10.first;
	cout<<"\nperson10 : "<<person10.second;
	
	cout<<"\nperson 9 : "<<person9.first;
	cout<<"\nperson 9 : "<<person9.second;
		
	
	cout<<"\n";
	system("pause");
	return 0;
}