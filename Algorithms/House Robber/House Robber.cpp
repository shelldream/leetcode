/**
	House Robber
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> dp;
        for(int i = 0;i < nums.size();i++)
        {
            if(i <= 1)
                dp.push_back(nums[i]);
            else
            {
                if(i-3 >= 0)
                    dp.push_back(max(dp[i-2],dp[i-3]) + nums[i]);
                else dp.push_back(dp[i-2] + nums[i]);
            }
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

int main()
{
    int data[] = {2,3,5,7,3,2,7,8};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    cout<<test.rob(nums)<<endl;
}
