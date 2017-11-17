/*
    Description:
        Permutations
        https://leetcode.com/problems/permutations/description/
    Author: shelldream
    Date:2017-10-31
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> path;
        set<int> not_visited(nums.begin(), nums.end()); 
        backtrace(ans, path, nums, not_visited);
        return ans;
    }
    
    void backtrace(vector<vector<int> >& ans, vector<int>&path, vector<int>& nums, set<int>& not_visited)
    {
        if (not_visited.empty())
        {    
            ans.push_back(path);
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int visit = nums[i];
            if (not_visited.count(visit) == 0) 
                continue;
            path.push_back(visit);
            not_visited.erase(visit);
            backtrace(ans, path, nums, not_visited);
            not_visited.insert(visit);
            path.pop_back();
        }
    }
};


int main()
{
    Solution solution;
    int data[] = {1,2,3,4};
    vector<int> nums(data, data+sizeof(data)/sizeof(int));
    vector<vector<int> > res = solution.permute(nums);

    for (size_t i = 0; i < res.size(); ++i)
    {
        for (size_t j = 0; j < res[i].size(); ++j)
            cout << res[i][j] << " ";
        cout << endl;    
    }
}

