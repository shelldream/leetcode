/*
	Move Zeroes
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while(i < nums.size())
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
            i++;
        }
        while(j < nums.size())
            nums[j++] = 0;
    }
};

int main()
{
	int data[] = {1,2,5,0,5,3,0,5,5,0};
	int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+n);
	Solution test;
	test.moveZeroes(nums);
	for(int i = 0;i < nums.size();i++)
	{
        cout<<nums[i]<<" ";
	}
}
