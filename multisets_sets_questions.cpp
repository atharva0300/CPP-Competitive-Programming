// multiset and set questions 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	/* 
		Question  : 
		https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4
	
	*/ 
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		multiset<long long>bags;
		for(int i=0;i<a;i++)		// O(n)
		{
			long long t;
			cin>>t;
			bags.insert(t);		// O(logn)
		}
		long long sum =0;
		for(int i=0;i<b;i++)	// O(n)
		{
			// the maximum candy will be stored at the last iterator 
			auto it = (--bags.end());
			long long count= *it;
			sum = sum + count;
			// erasing the candy 
			// erase using the iterator 
			// else, all the values with the same numbers
			// will get deleated 
			// we have to deleeate the last one , which we have consumed
			
			bags.erase(it);		// O(logn)
			bags.insert(count/2);	// O(logn)
		}
		cout<<sum<<"\n";
		
	}
	
	/* 
		
		More Questions : 
		https://www.hackerrank.com/challenges/cpp-sets/problem?fbclid=IwAR1Z1fv5RnGAqByvADCRUv4pYQAAmQ_zV5rgVVCagY-DneWu6TSWENdncsY
		
		https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/?fbclid=IwAR1n1FJUNpWIeq7dHY-HytoqqE1nbK9gD4jMjI2UWGTPE8GF4kHROCb7ouA
		
		https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew
		
		https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE
		
	*/
	system("pause");
	return 0;
}