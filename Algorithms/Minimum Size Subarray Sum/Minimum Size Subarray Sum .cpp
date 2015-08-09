/**
	Minimum Size Subarray Sum
	Author:Xiaojun Huang
	Date:2015-08-09

*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        int ans = INT_MAX;
        int j = 0;
        int sum = 0;
        while(i < nums.size())
        {
            while(sum < s && j < nums.size())
                sum += nums[j++];
            if(sum >= s && j-i < ans)
                ans = j-i;
            if(i < j)
                sum -= nums[i++];
        }
        if(ans < INT_MAX)
            return ans;
        else return 0;
    }
};

int main()
{
    int test[] = {10, 2, 3, 1, 2, 4, 3};
    int n = sizeof(test)/sizeof(test[0]);
    vector<int> nums(test,test+n);
    int s = 7;
    Solution solution;
    cout<<solution.minSubArrayLen(s,nums)<<endl;
}
