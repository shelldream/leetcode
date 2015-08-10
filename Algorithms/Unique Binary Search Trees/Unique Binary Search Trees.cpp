/**
	Unique Binary Search Trees
	Author:Xiaojun Huang
	Date:2015-08-10

*/

#include <iostream>
using namespace std;



/**
递归的方法会超时

class Solution {
public:
    int numTrees(int n) {
        return cal_num(1,n);
    }
    int cal_num(int low, int high)
    {
        if(low >= high)
            return 1;
        int ans = 0;
        for(int i = low;i <= high;i++)
            ans += cal_num(low, i-1)*cal_num(i+1,high);
        return ans;
    }
};

*/

/**动态规划的方法*/
class Solution {
public:
    int numTrees(int n) {
        int dp[1000];
        dp[0] = 1;
        for(int i = 1;i <= n;i++)
        {
            if(i==1)
                dp[1] = 1;
            else
            {
                dp[i] = 0;
                for(int j = 1;j <= i;j++)
                {
                    int left = j-1;
                    int right = i-j;
                    dp[i] += dp[left]*dp[right];
                }
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution solution;
    cout<<solution.numTrees(3)<<endl;
}
