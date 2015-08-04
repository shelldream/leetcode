/*
	Subsets
	Author:Xiaojun Huang
	Date:2015-08-04

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> path;
        ans.push_back(path);
        sort(nums.begin(),nums.end());
        traceback(ans, path, nums, 0);
        return ans;
    }
    void traceback(vector<vector<int> >& ans,vector<int>& path, vector<int>& nums, int index)
    {
        for(int i = index;i < nums.size();i++)
        {
            path.push_back(nums[i]);
            ans.push_back(path);
            traceback(ans, path, nums, i+1);
            path.pop_back();
        }
    }
};
int main()
{
    int data[] = {1,2,3};
    int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+n);
	Solution solution;
	vector<vector<int> > ans = solution.subsets(nums);
	for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

}
