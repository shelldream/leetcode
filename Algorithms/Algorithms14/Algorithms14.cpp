/*
    Longest Common Prefix
	Author:Xiaojun Huang
	Date:2015-07-13
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int strs_len = strs.size();
        if(strs_len==0)
            return "";
        ans = strs[0];
        for(int i = 1;i < strs_len;i++)
        {
            int min_len = min(ans.length(),strs[i].length());
            int j = 0;
            for(;j < min_len;j++)
            {
                if(strs[i][j] != ans[j])
                    break;
            }
            ans = ans.substr(0,j);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string test[] = {"abcdedf","abcd","abc"};
    int n = sizeof(test)/sizeof(test[0]);
    vector<string> strs(test,test+n);
    cout<<solution.longestCommonPrefix(strs)<<endl;
}

