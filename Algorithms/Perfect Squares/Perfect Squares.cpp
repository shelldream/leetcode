/**
	Perfect Squares
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 1;i <= n;i++)
        {
            int j = 1;
            int min_v = 100000;
            while(j*j <= i)
            {
                if(j*j == i)
                {
                    min_v = 1;
                    break;
                }
                min_v = min(min_v, dp[i- j*j] + 1);
                ++j;
            }
            dp[i] = min_v;
        }
        return dp[n];
    }
};

int main()
{
	Solution test;
	cout<<test.numSquares(12)<<endl;
}
