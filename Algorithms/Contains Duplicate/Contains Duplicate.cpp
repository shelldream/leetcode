/**
	Contains Duplicate
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> my_map;
        for(int i = 0;i < nums.size();i++)
        {
            if(my_map.count(nums[i]) == 1)
                return true;
            else my_map[nums[i]] = 1;
        }
        return false;
    }
};

int main()
{
    int data[] = {1,2,3,4,5,6,7,3};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    cout<<test.containsDuplicate(nums)<<endl;
}
