/**
	Minimum Path Sum
	Author:Xiaojun Huang
	Date:2015-08-27

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > dp(grid.size(),vector<int> (grid[0].size(), 0));
        if(grid.size() == 0)
            return 0;
        for(int i = 0;i < grid.size();i++)
            for(int j = 0;j < grid[i].size();j++)
        {
            if(i == 0 && j == 0)
                dp[0][0] = grid[i][j];
            else if(i == 0 && j)
                dp[i][j] = dp[i][j-1] + grid[i][j];
            else if(i && j == 0)
                dp[i][j] = dp[i-1][j] + grid[i][j];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    int data[3][3] = {{1,2,3},{-1,0,1},{4,5,-2}};
    vector<vector<int> > nums;
    for(int i = 0;i < 3;i++)
    {
        vector<int> tmp;
        for(int j = 0;j < 3;j++)
            tmp.push_back(data[i][j]);
        nums.push_back(tmp);
    }
    Solution solution;
    cout<<solution.minPathSum(nums);

}



