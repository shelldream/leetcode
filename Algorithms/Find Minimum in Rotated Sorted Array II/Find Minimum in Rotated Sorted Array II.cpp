/**
	Find Minimum in Rotated Sorted Array II
	Author:Xiaojun Huang
	Date:2015-09-11

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinInorder(vector<int>& nums, int low, int high)
    {
        int min_val = nums[low];
        while(low < high)
            if(min_val <= nums[low+1])
                low++;
            else
            {
                min_val = nums[low+1];
                break;
            }

        return min_val;
    }
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        if(low == high)
            return nums[low];
        while(low < high)
        {
            int mid = (low+high)/2;
            if(nums[mid] > nums[low] && nums[mid] > nums[high])
                low = mid;
            else if(nums[mid] < nums[low] && nums[mid] < nums[high])
                high = mid;
            else if(nums[mid] > nums[low] && nums[mid] < nums[high])
                high = mid;
            if(nums[mid] == nums[low] || nums[mid] == nums[high])
                return findMinInorder(nums, low,high);
            if(high-low == 1)
                return min(nums[low],nums[high]);
        }
    }
};

int main()
{
    //int data[] = {4,5,6,7,8,-1,1,2,3};
    //int data[] = {-1,0,2,3};
    //int data[] = {1,1,1,1,1,2,0,1};
    int data[] = {1,1,1,3};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.findMin(nums);

}
