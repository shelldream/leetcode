/*
	Combination Sum
	Author:Xiaojun Huang
	Date:2015-08-03

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        vector<int> path;
        backtrace(candidates, target, ans, path, 0, 0);
        return ans;
    }
    void backtrace(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int>& path, int current_sum, int index)
    {
        if(target<=0 || current_sum > target)
            return;
        if(current_sum == target)
        {
            ans.push_back(path);
        }
        else
        {
            for(int i = index;i < candidates.size();i++)
            {
                if(i == index || (i-1>= index && candidates[i] != candidates[i-1]))
                {
                    path.push_back(candidates[i]);
                    backtrace(candidates, target, ans, path, current_sum+candidates[i], i);
                    path.pop_back();
                }
            }
        }
    }
};

int main()
{
    int data[] = {3,3,3,6,7,7,3,3,3,2,2,2,2,3,6,7};
    int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+n);
	Solution solution;
	vector<vector<int> > ans = solution.combinationSum(nums,7);
	for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

}

/*˵��


*/
