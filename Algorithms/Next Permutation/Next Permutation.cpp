/**
	Next Permutation
	Author:Xiaojun Huang
	Date:2015-09-24

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return ;
        int i = nums.size()-2, j = nums.size()-1;
        while(i >= 0 && nums[i] >= nums[j])
        {
            i--;
            j--;
        }
        if(i >= 0)
        {
            int k = nums.size()-1;
            while(nums[k] <= nums[i])
                k--;
            int tmp = nums[i];
            nums[i] = nums[k];
            nums[k] = tmp;
            reverse(nums, j, nums.size()-1);
        }
        else{
            reverse(nums, 0, nums.size()-1);
        }
    }
    void reverse(vector<int>& nums, int i, int j)
    {
        while(i < j)
        {
            int tmp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = tmp;
        }
    }
};

int main()
{
	int data[] = {5,4,3,2,1};
	int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data, data+n);
	Solution test;
	test.nextPermutation(nums);
    for(int i = 0;i < nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
