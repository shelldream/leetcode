/*
	Description:
        Kth Largest Element in an Array
        https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    Author: shelldream
	Date:2017-10-29
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = partition(nums, 0, nums.size()-1);
        while (res != k-1)
        {
            if (res < k-1)
                res = partition(nums, res+1, nums.size()-1);
            else
                res = partition(nums, 0, res-1);
        }
        return nums[res];
    }

    int partition(vector<int>& nums, int low, int high)
    {
        int privot = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] <= privot)
                high--;

            nums[low] = nums[high];

            while (low < high && nums[low] >= privot)
                low++;
            nums[high] = nums[low];
        }
        
        nums[low] = privot;
        return low;
    }
};

int main()
{
    int data[] = {1,2,3,4,5,6};
    vector<int> nums(data, data+sizeof(data)/sizeof(int));
    Solution solution;
    cout << solution.findKthLargest(nums, 1) << endl;
    cout << solution.findKthLargest(nums, 2) << endl;
    cout << solution.findKthLargest(nums, 3) << endl;
}
