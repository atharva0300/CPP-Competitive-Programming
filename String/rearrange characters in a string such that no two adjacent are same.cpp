#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

struct Key{
	int freq;
	// store the frequency of character 
	char ch;
	
	// function for priority queue to store key 
	// according to freq 
	bool operator<(const Key& k) const{
		return freq<k.freq;
	}
};

// function to rearrange character of a string 
// so that no char repeat twice 
void rearrangeString(string str){
	int n = str.length();
	
	// store frequencies of all characters in a string 
	int count[MAX_CHAR] = {0};
	for(int i=0;i<n;i++){
		count[str[i]-'a']++;
	}
	
	// insert all characters with their frequencies 
	// into a priority_queue
	priority_queue<Key>pq;
	for(char c = 'a';c<='z';c++){
		int val = c;
		if(count[val]){
			pq.push(Key{count[val] , c});
		}
	}
	
	// 'str' that will store resultant value 
	str = "";
	
	// work as the previous visited element 
	// initial previous element be, ('#' and 
	// it's frequency '-1')
	Key prev{-1 , '#'};
	
	// traverse queue 
	while(!pq.empty()){
		// pop top element from queue and add it 
		// to string 
		Key k = pq.top();
		pq.top();
		str = str + k.ch;
		
		// if frequency if prevoious character is less 
		// than zero that means it is useless, we 
		// need not to push it 
		if(prev.freq > 0){
			pq.push(prev);
		}
		
		// make current character as the previous 'char'
		// decrease frequency by 'one'
		(k.freq)--;
		prev = k;
	}
	
	// if length of the resultant string and original 
	// string is not same then string is not valid 
	if(n!=str.length()){
		cout<<"Not valid string \n";
	}else{
		// valid string 
		cout<<str<<"\n";
	}
}

int main(){
	
	string str = "bbaa";
	rearrangeString(str);
	system("pause");
	return 0;
}