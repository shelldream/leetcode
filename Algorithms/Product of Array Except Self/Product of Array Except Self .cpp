/*
	Product of Array Except Self
	Author:Xiaojun Huang
	Date:2015-08-03
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int left_product = 1;
        for(int i = 0;i < nums.size();i++)
        {
            ans.push_back(left_product*nums[i]);
            left_product *= nums[i];
        }
        int right_product = 1;
        for(int j = nums.size()-1;j >= 0;j--)
        {
            if(j)
            {
                ans[j] = right_product*ans[j-1];
                right_product *= nums[j];
            }
            else ans[j] = right_product;
        }
        return ans;
    }
};


int main()
{
    int data[] = {1,2,3,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<"  ";
}
