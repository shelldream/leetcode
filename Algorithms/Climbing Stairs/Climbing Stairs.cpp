/**
	Climbing Stairs
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
using namespace std;

/**
�ݹ�ķ����ᳬʱ
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else return climbStairs(n-1) + climbStairs(n-2);
    }
};
*/

/**��̬�滮�ķ���*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.push_back(0);
        for(int i = 1;i <= n;i++)
        {
            if(i == 1 || i == 2)
                dp.push_back(i);
            else
            {
                dp.push_back(dp[i-1]+dp[i-2]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution test;
    cout<<test.climbStairs(3)<<endl;
}
