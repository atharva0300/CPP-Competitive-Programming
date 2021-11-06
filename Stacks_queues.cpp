// Stacks and queues 
#include<bits/stdc++.h>
using namespace std; 

int main()
{
	//Stack element using STL 
	// LIFO operation on stack
	// the element added agets added on the top 
	// the elemeent removed, is the top element 
	// LIFO ( last in first out )
	// opeartions - push , pop , top 
	
	// Queues
	// Concept - First in - first out ( FIFO )
	// operations - push , pop , front 
	// pop - pops the front element from the queue 
	
	// Stack code 
	cout<<"\nSTACK : \n";
	stack<int>s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while(!s.empty())
	{
		cout<<s.top()<<"\n";
		s.pop();
	}
	
	// Queue code 
	cout<<"\nQUEUE : \n";
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while(!q.empty())
	{
		cout<<q.front()<<"\n";
		q.pop();
	}
	
	cout<<"\n";
	
	system("pause");
	return 0;
}