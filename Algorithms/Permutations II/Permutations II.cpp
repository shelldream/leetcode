/**
	Permutations II
	Author:Xiaojun Huang
	Date:2015-09-25

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> path;
        backtrace(ans, path, nums);
        return ans;
    }
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void backtrace(vector<vector<int> >& ans, vector<int>& path, vector<int>& rest)
    {
        if(rest.size() == 0)
        {
            ans.push_back(path);
            return;
        }
        set<int> visited;
        for(int i = 0;i < rest.size();i++)
        {
            swap(rest[0], rest[i]);
            if(visited.count(rest[0]) == 0)
            {
                path.push_back(rest[0]);
                vector<int> tmp(rest.begin()+1, rest.end());
                backtrace(ans, path, tmp);
                path.pop_back();
                visited.insert(rest[0]);
            }
            swap(rest[0], rest[i]);
        }
    }
};

int main()
{
	int data[] = {1,3,1,2};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    vector<vector<int> > ans = test.permuteUnique(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }
}
