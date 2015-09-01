/**
	Sort Colors
	Author:Xiaojun Huang
	Date:2015-09-01

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i0 = -1;
        int i1 = -1;
        int i2 = -1;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == 0)
            {
                nums[++i2] = 2;
                nums[++i1] = 1;
                nums[++i0] = 0;
            }
            else if(nums[i] == 1)
            {
                nums[++i2] = 2;
                nums[++i1] = 1;
            }
            else
            {
                nums[++i2] = 2;
            }
            i++;
        }
    }
};

int main()
{
    int data[] = {1,0,1,2,1,1,1,0,2,2,1,0,1};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data, data+n);
    Solution solution;
    solution.sortColors(nums);
    for(int i = 0;i < n;i++)
        cout<<nums[i]<<"  ";
    cout<<endl;
}
