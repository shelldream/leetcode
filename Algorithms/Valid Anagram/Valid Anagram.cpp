/**
	Valid Anagram
	Author:Xiaojun Huang
	Date:2015-09-03

*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        if(s_len != t_len)
            return false;
        int s_map[26];
        int t_map[26];
        for(int i = 0;i < 26;i++)
        {
            s_map[i] = 0;
            t_map[i] = 0;
        }
        for(int i = 0;i < s_len;i++)
            s_map[s[i]-'a'] += 1;
        for(int i = 0;i < t_len;i++)
            t_map[t[i]-'a'] += 1;
        for(int i = 0;i < 26;i++)
        {
            if(s_map[i] != t_map[i])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    //cout<<solution.isAnagram("abcd", "badc")<<endl;
    cout<<solution.isAnagram("a", "d")<<endl;
}
