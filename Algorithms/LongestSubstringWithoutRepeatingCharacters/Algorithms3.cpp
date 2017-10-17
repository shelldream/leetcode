/*
    Description: 
        Longest Substring Without Repeating Characters
        https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Author: shelldream
    Date: 2017-10-17
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<char, size_t> char_idx_map;
        int left = 0;
        for (size_t i=0; i < s.size(); ++i)
        {
            if (char_idx_map.find(s[i]) != char_idx_map.end())
            {
                int j = left;
                while(j < char_idx_map[s[i]])
                {
                    map<char,size_t>::iterator iter = char_idx_map.find(s[j++]);
                    char_idx_map.erase(iter);
                }
                left = (int)char_idx_map[s[i]] + 1;
            }
            char_idx_map[s[i]] = i;
            int win = (int)i - left + 1;
            res = std::max(res, win);
        }
        return res;
    }
};



int main()
{
    Solution solution;
    string tc1 = "abcabcbb";
    string tc2 = "bbbbb";
    string tc3 = "pwwkew";
    string tc4 = "";
    string tc5 = "abba";

    cout << solution.lengthOfLongestSubstring(tc1) << endl;
    cout << solution.lengthOfLongestSubstring(tc2) << endl;
    cout << solution.lengthOfLongestSubstring(tc3) << endl;
    cout << solution.lengthOfLongestSubstring(tc4) << endl;
    cout << solution.lengthOfLongestSubstring(tc5) << endl;
}
