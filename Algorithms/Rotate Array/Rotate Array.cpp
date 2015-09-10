/**
	Rotate Array
	Author:Xiaojun Huang
	Date:2015-09-10

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        rotateSubArray(nums, nums.size()-k, nums.size()-1);
        rotateSubArray(nums, 0, nums.size()-k-1);
        rotateSubArray(nums, 0, nums.size()-1);
    }
    void rotateSubArray(vector<int>& nums, int i ,int j)
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
    int data[] = {1,2,3,4,5,6,7};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    for(int j = 0;j <= n+10;j++)
    {
        vector<int> tmp = nums;
        test.rotate(tmp,j);
        for(int i = 0;i < tmp.size();i++)
            cout<<tmp[i]<<"  ";
        cout<<endl;
    }
}
