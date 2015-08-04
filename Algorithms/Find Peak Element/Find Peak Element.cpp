/*
	Find Peak Element
	Author:Xiaojun Huang
	Date:2015-08-04

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            if(low == high)
                return low;
            int mid = (low+high)/2;
            if(nums[mid] >= nums[mid+1])//ÏÂ½µ
                high = mid;
            else low = mid+1;
        }
    }
};
int main()
{
    //int data[] = {1,2,3,4,1};
    int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.findPeakElement(nums)<<endl;
}
