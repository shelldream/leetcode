/*
 *	Description: Combination Sum IV   https://leetcode.com/problems/combination-sum-iv/
 *  Author: Xiaojun Huang
 *  Date: 2016-07-30
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target){
		vector<int> dp(target+1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for(size_t j = 0; j < nums.size(); ++j)
			{
				if (i - nums[j] >= 0)
					dp[i] += dp[i-nums[j]];
			}
		}
		return dp[target];
	}
};

int main()
{
    int data[] = {2,1,3};
	int n = sizeof(data)/sizeof(data[0]);
	vector<int> test(data, data+n);
	Solution solution;
	cout<<solution.combinationSum4(test, 4)<<endl;
}
