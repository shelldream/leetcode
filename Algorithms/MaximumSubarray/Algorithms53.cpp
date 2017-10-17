/*
    Description: 
        Maximum Subarray
        https://leetcode.com/problems/maximum-subarray/description/
    Author: shelldream
    Date: 2017-10-18
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> max_dp(size, 0);
        int res = nums[0];
        max_dp[0] = nums[0];
        for (size_t i = 1; i < size; ++i) 
        {
            max_dp[i] = max(nums[i], max_dp[i-1]+nums[i]);
            res = max(max_dp[i], res);
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int data[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> ts1(data, data+sizeof(data)/sizeof(int));
    cout << solution.maxSubArray(ts1) << endl;
}
