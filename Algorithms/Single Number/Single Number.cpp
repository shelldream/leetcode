/**
	Single Number
	Author:Xiaojun Huang
	Date:2015-08-06
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int tmp = nums[0];
        for(int i = 1; i < nums.size();i++)
            tmp = tmp^nums[i];
        return tmp;
    }
};

int main()
{
	int data[] = {2,2,2,2,2,2,1,1,1,1,1,1,3,3,3,3,3,3,6};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+size);
	Solution solution;
	cout<<solution.singleNumber(nums)<<endl;
}
