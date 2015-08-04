/*
	Subsets II
	Author:Xiaojun Huang
	Date:2015-08-04

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> path;
        ans.push_back(path);
        sort(nums.begin(),nums.end());
        backtrace(ans, path, nums, 0);
        return ans;
    }
    void backtrace(vector<vector<int> >& ans, vector<int>& path, vector<int>& nums, int index)
    {
        for(int i = index;i < nums.size();i++)
        {
            if(i == index ||(i-1>=index && nums[i-1] != nums[i]))
            {
                path.push_back(nums[i]);
                ans.push_back(path);
                backtrace(ans, path, nums, i+1);
                path.pop_back();
            }
        }
    }
};

int main()
{
    int data[] = {1,2,2};
    int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+n);
	Solution solution;
	vector<vector<int> > ans = solution.subsetsWithDup(nums);
	for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

}
