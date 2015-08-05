/*
	Maximal Square
	Author:Xiaojun Huang
	Date:2015-08-05
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        vector<vector<int> > dp;
        for(int i = 0;i < matrix.size();i++)
        {
            vector<int> tmp;
            for(int j = 0;j < matrix[i].size();j++)
            {
                if(matrix[i][j] == '1')
                    tmp.push_back(1);
                else tmp.push_back(0);
            }
            dp.push_back(tmp);
        }
        int max_square = 0;
        for(int i = 0;i < dp.size();i++)
            for(int j = 0;j < dp[i].size();j++)
            {
                if(matrix[i][j] == '1')
                {
                    int x,y,z;

                    if(i==0 && j)
                    {
                        x = dp[i][j-1];
                        y = 0;
                        z = 0;
                    }
                    else if(i && j==0)
                    {
                        x = 0;
                        y = dp[i-1][j];
                        z = 0;
                    }
                    else if(i == 0 && j == 0)
                    {
                        x = 0;
                        y = 0;
                        z = 0;
                    }
                    else
                    {
                        x = dp[i][j-1];
                        y = dp[i-1][j];
                        z = dp[i-1][j-1];
                    }
                    dp[i][j] = min(min(x,y),z) + 1;
                    if(dp[i][j] > max_square)
                        max_square = dp[i][j];
                }
            }
        return max_square*max_square;
    }
};


int main()
{
    string test[] = {"10100","10111","11111","10010"};
    int n = sizeof(test)/sizeof(test[0]);
    vector<vector<char> > matrix;
    for(int i = 0;i < n;i++)
    {
        vector<char> tmp;
        for(int j = 0;j < test[i].size(); j++)
            tmp.push_back(test[i][j]);
        matrix.push_back(tmp);
    }
    Solution solution;
    cout<<solution.maximalSquare(matrix)<<endl;
}
