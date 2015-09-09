/**
	Majority Element
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if(count == 0)
            {
                ans = nums[i];
                count = 1;
            }
            else
            {
                if(nums[i] == ans)
                    count++;
                else count--;
            }
        }
        return ans;
    }
};

int main()
{
    int data[] = {2,3,5,7,2,3,2,3,2,2,2,3,2,7,8};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    cout<<test.majorityElement(nums)<<endl;
}
