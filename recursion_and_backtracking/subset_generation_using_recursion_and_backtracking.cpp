// subset generation using recursion and backtracking 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets;
void generate(vector<int>&subset, int i, vector<int>&nums)
{
	if(i==nums.size())
	{
		subsets.push_back(subset);
		return;
	}
	// function call when the ith element is not in the subset
	generate(subset , i+1 , nums);
	
	// ith element in subset
	subset.push_back(nums[i]);
	generate(subset , i+1, nums);
	subset.pop_back();
}
int main()
{
	/* 
		Question : 
		
		Given an integer array nums of unique elements, return all possible subsets (the power set).

		The solution set must not contain duplicate subsets. Return the solution in any order.

		 

		Example 1:

		Input: nums = [1,2,3]
		Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
		Example 2:

		Input: nums = [0]
		Output: [[],[0]]
	
	*/
	/* 
	
		number of subsets : 2 ^ ( number of elements )
		
	*/ 
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	vector<int>empty;
	generate(empty , 0, nums);
	
	for(auto subset : subsets)
	{
		for(auto y :subset )
		{
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	system("pause");
	return 0;
}