/*
	Longest Substring Without Repeating Characters
	Author:Xiaojun Huang
	Date:2015-6-30
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    map<char,int> char_count;
    bool is_valid(char c)
    {
        map<char,int>::iterator iter;
        iter = char_count.find(c);
        if(iter == char_count.end())
            return true;
        else
            return false;
    }
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len==0)
            return 0;
        if(len == 1)
            return 1;
        int i,j;
        i = 0;
        j = 1;
        char_count[s[i]] = 1;
        int max_len = 1;
        while(j < len)
        {
            while(is_valid(s[j]) && j<len)
            {
                int now_len = j-i+1;
                if(now_len > max_len)
                    max_len = now_len;
                char_count[s[j]] = 1;
                j++;
            }
            while(!is_valid(s[j]) && i<=j)
            {
                char_count.erase(s[i]);
                i++;
            }
        }
        return max_len;
    }
};

int main()
{
    Solution solution ;
    string test = "abceabcbb";
    cout<<solution.lengthOfLongestSubstring(test)<<endl;
}

