/**
	Word Break
	Author:Xiaojun Huang
	Date:2015-08-16

*/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, set<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i = 0;i < n;i++)
        {
            if(i==0 || dp[i-1])
            {
                for(int j = i;j < n;j++)
                {
                    if(wordDict.count(s.substr(i, j-i+1)) > 0)
                        dp[j] = true;
                    //cout<<j<<"  "<<dp[j]<<"  "<<s.substr(i, j-i+1)<<endl;
                }
            }
        }
        return dp[n-1];
    }
};

int main()
{
    Solution solution;
    set<string> wordDict;
    string test[] = {"leetcode", "code", "aaaa", "aaa"};
    int n = sizeof(test)/sizeof(test[0]);
    for(int i = 0;i<n;i++)
        wordDict.insert(test[i]);
    cout<<solution.wordBreak("leetcode",wordDict);
    //cout<<solution.wordBreak("aaaaaaa",wordDict);
}
