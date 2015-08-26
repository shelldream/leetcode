/*
	Combinations
	Author:Xiaojun Huang
	Date:2015-07-27

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> path;
        backtrace(ans, path, 1, n,k);
        return ans;
    }
    void backtrace(vector<vector<int> >& ans,vector<int>& path, int start, int n, int k)
    {
        if(k == 0)
            ans.push_back(path);
        else{
            for(int i = start;i <= n;i++)
            {
                path.push_back(i);
                backtrace(ans, path, i+1, n, k-1);
                path.pop_back();
            }
        }
    }
};
int main()
{
    Solution solution;

    vector<vector<int> > ans = solution.combine(4,2);
    //vector<vector<int> > ans = solution.helper(1,1,1);
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

/*หตร๗


*/
