/**
	Single Number II
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int bit_cnt[32] = {0};
        for(int i = 0;i < 32;i++)
        {
            for(int j = 0;j < nums.size();j++)
                bit_cnt[i] += (nums[j] >> i)&1;
            ans |= (bit_cnt[i]%3)<<i;
        }
        return ans;
    }
};

int main()
{

	int data[] = {2,3,1,1,1,2,2};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
	Solution test;
	cout<<test.singleNumber(nums)<<endl;
}
