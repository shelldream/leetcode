/*
	3Sum Closest
	Author:Xiaojun Huang
	Date:2015-07-23

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int dis = 1000000;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
        {
            int tmp;
            int low = i+1;
            int high = nums.size()-1;
            while(low<high)
            {
                int now = nums[i] + nums[low] + nums[high];
                int distance = abs(now - target);
                if (distance < dis)
                {
                    dis = distance;
                    ans = now;
                }
                if(now > target)
                    high--;
                else if (now < target)
                    low++;
                else return target;
            }
        }
        return ans;
    }
};

int main()
{
	int data[] = {-1, 2, 1, -4};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+size);
	Solution solution;
    cout<<solution.threeSumClosest(nums,1)<<endl;
}
