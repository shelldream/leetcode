/*
	Triangle
	Author:Xiaojun Huang
	Date:2015-08-27

*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        vector<vector<int> > dp;
        for(int level = 0;level < n;level++)
        {
            vector<int> tmp;
            for(int k = 0;k < triangle[level].size();k++)
            {
                if(level == 0)
                    tmp.push_back(triangle[0][0]);
                else
                {
                    int a,b;
                    a = INT_MAX;
                    b = INT_MAX;
                    if(k-1 >= 0 && k-1 < triangle[level-1].size())
                    {
                        a = dp[level-1][k-1];
                    }

                    if(k >= 0 && k < triangle[level-1].size())
                        {
                            b = dp[level-1][k];
                        }
                    tmp.push_back(min(a,b) + triangle[level][k]);
                }
            }
            dp.push_back(tmp);
        }
        int ans = INT_MAX;
        for(int i = 0;i < dp[n-1].size();i++)
            if(ans > dp[n-1][i])
                ans = dp[n-1][i];
        return ans;
    }
};

int main()
{
    int data[10] = {2,3,4,6,5,7,4,1,8,3};
    vector<vector<int> > nums;
    int index = 0;
    for(int i = 1;i <= 4;i++)
    {
        int j = 1;
        vector<int> tmp;
        while(j <= i)
        {
            tmp.push_back(data[index++]);
            j++;
        }
        nums.push_back(tmp);
    }
    Solution solution;
    cout<<solution.minimumTotal(nums)<<endl;
}
