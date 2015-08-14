/**
	Maximum Product Subarray
	Author:Xiaojun Huang
	Date:2015-08-14

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int max_val = nums[0];
        int min_val = nums[0];
        int ans = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            int a = nums[i]*max_val;
            int b = nums[i]*min_val;
            max_val = max(max(a,b), nums[i]);
            min_val = min(min(a,b), nums[i]);
            if(max_val > ans)
                ans = max_val;
        }
        return ans;
    }
};

int main()
{
    int data[] = {2,3,-2,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.maxProduct(nums);
}
