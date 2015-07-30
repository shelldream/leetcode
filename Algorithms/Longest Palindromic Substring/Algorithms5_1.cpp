/*
	Longest Palindromic Substring
	Author:Xiaojun Huang
	Date:2015-07-01
	Description:利用动态规划求解
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.length();
        int max_len = 1;
        int start = 0;
        string ans = "";
        bool flag[1000][1000];//flag[i][j]的值表示字符串s从i到j之间的子字符串是否为回文
        for(int i = 0;i < s_len;i++)
            for(int j = 0;j < s_len;j++)
            {
                if(i>=j)
                    flag[i][j] = true;//考虑j=i+1的情况
                else
                    flag[i][j] = false;
            }
        for(int j = 1;j < s_len;j++)
            for(int i = 0;i < j;i++)
            {
                if(s[i] == s[j])
                {
                    flag[i][j] = flag[i+1][j-1];
                    if(flag[i][j] && j-i+1 > max_len)
                    {
                        max_len = j-i+1;
                        start = i;
                    }
                }
                else
                    flag[i][j] = false;
            }
        ans = s.substr(start,max_len);
        return ans;
    }
};

int main()
{
    string test1 = "abaaaaaaea";
    string test2 = "aa";
    string test3 = "aba";
    string test4 = "a";
    string test5 = "tattarrattat";
    string test6 = "";
    Solution solution;
    cout<<solution.longestPalindrome(test1)<<endl;
    cout<<solution.longestPalindrome(test2)<<endl;
    cout<<solution.longestPalindrome(test3)<<endl;
    cout<<solution.longestPalindrome(test4)<<endl;
    cout<<solution.longestPalindrome(test5)<<endl;
    cout<<solution.longestPalindrome(test6)<<endl;
}
