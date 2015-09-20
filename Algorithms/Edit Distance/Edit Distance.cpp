/**
	Edit Distance
	Author:Xiaojun Huang
	Date:2015-09-20

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size()+1;
        int column = word2.size()+1;
        vector<vector<int> > dp(row, vector<int> (column,0));
        for(int i = 0;i < row;i++)
            dp[i][0] = i;
        for(int j = 0;j < column;j++)
            dp[0][j] = j;
        for(int i = 1;i < row;i++)
            for(int j=1;j < column;j++)
        {
            dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0:1));
        }
        return dp[row-1][column-1];
    }
};

int main()
{
    string word1("abc");
    string word2("abcd");
    Solution test;
    cout<<test.minDistance(word1, word2)<<endl;
}

