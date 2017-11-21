/*
    Description:
        Longest Increasing Subsequence
        https://leetcode.com/problems/longest-increasing-subsequence/description/
    Author: shelldream
    Date:2017-11-20
*/
#include <iostream>
#include <vector>
using namespace std;

/********************O(n^2)的解法**************************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i-1; j >= 0; --j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);    
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};


int main()
{
    Solution solution;
    //int data[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int data[] = {1,3,6,7,9,4,10,5,6};
    vector<int> nums(data, data+sizeof(data)/sizeof(int));
    cout << solution.lengthOfLIS(nums) << endl;
}

