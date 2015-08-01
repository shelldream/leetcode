/*
	Search Insert Position
	Author:Xiaojun Huang
	Date:2015-08-01
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int k = nums.size()-1;
        int low = 0;
        int high = k;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid+1;
            else high = mid-1;
        }
        if(high == -1)
            return 0;
        if(low == k+1)
            return k+1;
        return low;
    }
};


int main()
{
    int data[] = {1, 3, 5, 6};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.searchInsert(nums,5)<<endl;
    cout<<solution.searchInsert(nums,2)<<endl;
    cout<<solution.searchInsert(nums,7)<<endl;
    cout<<solution.searchInsert(nums,0)<<endl;
}

