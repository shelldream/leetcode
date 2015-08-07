/**
	Maximum Subarray
	Author:Xiaojun Huang
	Date:2015-08-07

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long ans = -100000000;
        vector<int> max_subarray;
        for(int i = 0;i < nums.size();i++)
        {
            if(i==0)
                max_subarray.push_back(nums[i]);
            else
            {
                if(nums[i] + max_subarray[i-1] > nums[i])
                    max_subarray.push_back(nums[i] + max_subarray[i-1]);
                else
                    max_subarray.push_back(nums[i]);
            }
            if(max_subarray[i] > ans)
                ans = max_subarray[i];
        }
        return ans;
    }
};


int main()
{
    int data[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.maxSubArray(nums)<<endl;
}
