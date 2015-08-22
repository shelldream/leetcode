/**
	Find Minimum in Rotated Sorted Array
	Author:Xiaojun Huang
	Date:2015-08-22

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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
            if(high-low == 1)
                return min(nums[low],nums[high]);
        }
    }
};

int main()
{
    int data[] = {4,5,6,7,8,-1,1,2,3};
    //int data[] = {-1,0,2,3};
    //int data[] = {1};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.findMin(nums);

}
