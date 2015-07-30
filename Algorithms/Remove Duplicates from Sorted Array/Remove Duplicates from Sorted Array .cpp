/*
	Remove Duplicates from Sorted Array
	Author:Xiaojun Huang
	Date:2015-07-30
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = -1;
        while(i < nums.size())
        {
            if(i==0 || nums[i] != nums[i-1])
            {
                j++;
                nums[j] = nums[i];
            }
            i++;
        }
        return j+1;
    }
};


int main()
{
    int data[] = {1,1,1,2,2,2,3,3,4,5,6,6,6,6};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    int ans = solution.removeDuplicates(nums);
    cout<<ans<<endl;
    for(int m = 0;m<ans;m++)
        cout<<nums[m]<<" ";
    cout<<endl;
}
