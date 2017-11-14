/*
    Description:
        Word Break
        https://leetcode.com/problems/word-break/description/
    Author: shelldream
    Date:2017-11-14
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        if (s.size() == 0)
            return false;

        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j=i; j >= 0 && !dp[i]; --j)
            {
                if (dict.count(s.substr(j, i-j+1)) > 0)
                {
                    if (j-1 >= 0)
                        dp[i] = dp[j-1];
                    else
                        dp[i] = true;
                }
            }
        }

        return dp[s.size()-1];
    }
};

int main()
{
    Solution solution;
    string test[4] = {"leet", "code", "lint", "a"};
    vector<string> wordDict(test, test+4);
    cout << solution.wordBreak(string("leetcode"), wordDict) << endl;
}

