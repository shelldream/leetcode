/*
	Combination Sum III
	Author:Xiaojun Huang
	Date:2015-08-04

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> path;
        for(int i = 1;i <= 9;i++)
        {
            path.push_back(i);
            backtrace(ans, path, i, k-1, n, i);
            path.pop_back();
        }
        return ans;
    }
    void backtrace(vector<vector<int> >& ans, vector<int>& path, int sum, int k, int target, int index)
    {

        //for(int m = 0;m < path.size();m++)
        //    cout<<path[m]<<" ";
        //cout<<endl;
        if(k < 0 || index > 9 || index > target || sum > target)
            return;
        if(sum == target && k == 0)
        {
            ans.push_back(path);
        }
        else if(sum < target && k > 0)
        {
            for(int j = index+1; j <=9 ;j++)
            {
                path.push_back(j);
                backtrace(ans, path, sum+j, k-1, target, j);
                path.pop_back();
            }
        }
    }
};

int main()
{
	Solution solution;
	vector<vector<int> > ans = solution.combinationSum3(3,9);
	for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

}

/*
หตร๗


*/
