/**
	Jump Game
	Author:Xiaojun Huang
	Date:2015-08-11

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        int max_index = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            if(max_index < i)
                return false;
            if(max_index >= nums.size()-1)
                return true;
            int current_max_index = i+nums[i];
            if(current_max_index > max_index)
                max_index = current_max_index;
        }
        if(max_index >= nums.size()-1)
            return true;
        else return false;
    }
};

int main()
{
    int data[] = {2,3,1,1,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.canJump(nums)<<endl;
}



