/**
	Remove Element
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        for(int j = 0;j < nums.size();j++)
        {
            if(nums[j] != val)
                nums[++i] = nums[j];
        }
        while(nums.size() > i+1)
            nums.pop_back();
        return i+1;
    }
};

int main()
{
    int data[] = {1,2,4,2,6,4,7,8,9,0,3,2,5,1,2,5,7,2};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    cout<<n<<endl;
    Solution test;
    cout<<test.removeElement(nums,2)<<endl;
    for(int i = 0;i < nums.size();i++)
        cout<<nums[i]<<"  ";
}
