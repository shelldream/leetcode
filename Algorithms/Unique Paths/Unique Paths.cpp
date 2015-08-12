/**
	Unique Paths
	Author:Xiaojun Huang
	Date:2015-08-12

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        int dp[100][100];
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
            {
                if(i==0 || j == 0)
                    dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution solution;
    cout<<solution.uniquePaths(2,2)<<endl;
}



