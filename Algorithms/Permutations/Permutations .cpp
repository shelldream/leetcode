/*
	Permutation
	Author:Xiaojun Huang
	Date:2015-08-06

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        vector<int> path;
        backtrace(ans, path, nums);
        return ans;
    }
    void backtrace(vector<vector<int> >& ans,vector<int>& path, vector<int>& rest)
    {
        if(!rest.size())
            ans.push_back(path);
        for(int i = 0;i < rest.size();i++)
        {
            path.push_back(rest[i]);
            vector<int> tmp;
            for(int j = 0;j < rest.size();j++)
                if(j != i)
                    tmp.push_back(rest[j]);
            backtrace(ans, path, tmp);
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
    vector<vector<int> > ans = solution.permute(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }
}
