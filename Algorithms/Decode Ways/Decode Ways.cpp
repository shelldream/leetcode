/**
	Decode Ways
	Author:Xiaojun Huang
	Date:2015-09-21

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s == "")
            return 0;
        vector<int> dp(s.size(),0);
        for(int i = 0;i < s.size();i++)
        {
            if(i == 0)
            {
                if(s[i] == '0')
                    return 0;
                else dp[0] = 1;
            }
            else
            {
                if(s[i] == '0')
                    if(s[i-1] != '1' && s[i-1] != '2')
                        return 0;
                    else dp[i] = (i-2 >= 0) ? dp[i-2] : 1;
                else//当前这位不是0
                {
                    if(s[i-1] != '1' && s[i-1] != '2')
                        dp[i] = dp[i-1];
                    else//如果前一位是1或2
                    {
                        if(s[i-1] == '1')
                            dp[i] = dp[i-1] + ((i-2 >= 0) ? dp[i-2] : 1);
                        else{
                            if(s[i] >= '1' && s[i] <= '6')
                                dp[i] = dp[i-1] + ((i-2 >= 0) ? dp[i-2] : 1);
                            else dp[i] = dp[i-1];
                        }
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};

int main()
{
    string s = "103";
    Solution test;
    cout<<test.numDecodings(s)<<endl;
}

