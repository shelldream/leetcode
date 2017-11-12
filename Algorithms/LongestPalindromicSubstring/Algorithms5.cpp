/*
    Description:
        Longest Palindromic Substring
        https://leetcode.com/problems/longest-palindromic-substring/description/
    Author: shelldream
    Date:2017-11-12
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t len = s.size();
        if (0 == len)
            return string();
        vector<vector<bool> > isPalindrome(len, vector<bool>(len, false));
        size_t max_start = 0;
        int max_len = 1;
        for (size_t i = 0; i < len; ++i)
            isPalindrome[i][i] = true;
        
        for (size_t i = 1; i < len; ++i)
        {
            for (size_t j = 0; j < len-i; ++j)
            {
                if (s[j] == s[j+i] && (1 == i || isPalindrome[j+1][j+i-1]))
                {
                    isPalindrome[j][j+i] = true;
                    if (i+1 > max_len)
                    {
                        max_len = i+1;
                        max_start = j;    
                    } 
                }
            }
        }
        return s.substr(max_start, max_len);
    }
};


int main()
{
    Solution solution;
    string test = "AAAABBBAA";
    cout << solution.longestPalindrome(test) << endl;
}
