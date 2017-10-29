/*
	Description:
        Sliding Window Maximum
        https://leetcode.com/problems/sliding-window-maximum/description/
    Author: shelldream
	Date:2017-10-29
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        list<int> window_max;
        for (size_t i=0; i < nums.size(); ++i)
        {
            while (!window_max.empty() && nums[window_max.back()] < nums[i])
                window_max.pop_back();
            
            window_max.push_back(int(i));
            int max_index = window_max.front();
            if (max_index <= int(i-k))
                window_max.pop_front();
            
            if (i >= k-1)
                res.push_back(nums[window_max.front()]);
        }
        return res;
    }
};


int main()
{
    Solution solution;
    
    {
        int data[] = {1,3,-1,-3,5,3,6,7};
        vector<int> nums(data, data+sizeof(data)/sizeof(int));
        vector<int> res = solution.maxSlidingWindow(nums, 3);
        for (size_t i=0; i < res.size(); ++i)
            cout << res[i] << "  ";
        cout << endl;
    }
}

