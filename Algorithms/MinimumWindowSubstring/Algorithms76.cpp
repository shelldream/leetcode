/*
	Description: 
        Minimum Window Substring  
        https://leetcode.com/problems/minimum-window-substring/description/
    Author: shelldream
	Date: 2017-10-12
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> target_count;
        for (size_t i = 0; i < t.size(); ++i)
        {
            target_count[t[i]] += 1;    
        }
        
        map<char, int> current_count;
        int begin=0, end = 0;
        long min_win_size = 1e10;
        size_t win_left = 0;
        set<char> matched_char_set;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (target_count.find(s[i]) != target_count.end())
            {    
                current_count[s[i]] += 1;
                if (current_count[s[i]] >= target_count[s[i]])
                    matched_char_set.insert(s[i]);
            }
            
            if (target_count.size() == matched_char_set.size())
            {
                while(win_left < s.size() && (target_count.find(s[win_left]) == target_count.end() || current_count[s[win_left]] > target_count[s[win_left]]))
                {
                    if (target_count.find(s[win_left]) != target_count.end() && current_count[s[win_left]] > target_count[s[win_left]])
                        current_count[s[win_left]]--;
                    ++win_left;
                }
                
                if ((i-win_left) < min_win_size)
                {
                    min_win_size = i - win_left;
                    begin = win_left;
                    end = i;    
                }
            }
        }
        if (target_count.size() == matched_char_set.size())
            return s.substr(begin, end-begin+1);
        else
            return string();
    }
};


int main()
{
    string tc1_s = "ADOBECODEBANC";
    string tc1_t = "ABC";
    string tc2_s = "ADOBECODEBANC";
    string tc2_t = "ABCX";
    string tc3_s = "ADOBECODEBANC";
    string tc3_t = "ABCDENO";
    string tc4_s = "A";
    string tc4_t = "A";
    string tc5_s = "A";
    string tc5_t = "AA";
    Solution solution;
    cout << solution.minWindow(tc1_s, tc1_t) << endl;
    cout << solution.minWindow(tc2_s, tc2_t) << endl;
    cout << solution.minWindow(tc3_s, tc3_t) << endl;
    cout << solution.minWindow(tc4_s, tc4_t) << endl;
    cout << solution.minWindow(tc5_s, tc5_t) << endl;
}
