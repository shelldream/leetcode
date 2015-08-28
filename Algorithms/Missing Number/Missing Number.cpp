/*
	Missing Number
	Author:Xiaojun Huang
	Date:2015-08-28

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int target = n*(n+1)/2;
        for(int i = 0;i < nums.size();i++)
            target -= nums[i];
        return target;
    }
};

int main()
{
	Solution solution;
    int data[] = {0,1,2,3,5,6,7};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    cout<<solution.missingNumber(nums);
}

