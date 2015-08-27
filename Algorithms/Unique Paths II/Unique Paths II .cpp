/**
	Unique Paths II
	Author:Xiaojun Huang
	Date:2015-08-27

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        bool isObstacled = false;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = 0;i < n;i++)
            if(!isObstacled && obstacleGrid[0][i] == 0)
                dp[0][i] = 1;
            else
            {
                dp[0][i] = 0;
                isObstacled = true;
            }
        isObstacled = false;
        for(int i = 0;i < m;i++)
            if(!isObstacled && obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
            {
                dp[i][0] = 0;
                isObstacled = true;
            }
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++)
        {
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                cout<<i<<"  "<<j<<"  "<<dp[i][j]<<endl;
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > test;
    int data[3][3] = {{0,0,0},{0,1,0},{0,1,0}};
    for(int i = 0;i < 3;i++)
    {
        vector<int> tmp;
        for(int j = 0;j < 3;j++)
            tmp.push_back(data[i][j]);
        test.push_back(tmp);
    }
    cout<<solution.uniquePathsWithObstacles(test)<<endl;
}



