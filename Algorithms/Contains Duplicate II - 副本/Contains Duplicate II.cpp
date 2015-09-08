/**
	Contains Duplicate II
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> my_map;
        for(int i = 0;i < nums.size();i++)
        {
            if(my_map.count(nums[i]) == 0)
                my_map[nums[i]] = i;
            else
            {
                if(i - my_map[nums[i]] <= k)
                    return true;
                my_map[nums[i]] = i;
            }
        }
        return false;
    }
};

int main()
{
    //int data[] = {1,2,3,3,4,5,6,7,3};
    int data[] = {1,1};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    cout<<test.containsNearbyDuplicate(nums,1)<<endl;
}
