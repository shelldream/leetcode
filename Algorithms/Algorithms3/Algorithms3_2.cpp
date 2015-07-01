/*
	ZigZag Conversion
	Author:Xiaojun Huang
	Date:2015-07-01
*/

#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int char_locs[256];
        memset(char_locs,-1,sizeof(char_locs));
        int len = s.length();
        if(len==0)
            return 0;
        if(len==1)
            return 1;
        int i,j;
        i = 0;
        j = 1;
        char_locs[s[i]] = 0;
        int max_len = 0;
        while(j<len)
        {
            if(char_locs[s[j]] >= i)
                i = char_locs[s[j]] + 1;
            char_locs[s[j]] = j;
            int now_len = j-i+1;
            if(now_len > max_len)
                max_len = now_len;
            j++;
        }
        return max_len;
    }
};

int main()
{
    Solution solution ;
    string test = "abcabcbb";
    cout<<solution.lengthOfLongestSubstring(test)<<endl;
}
