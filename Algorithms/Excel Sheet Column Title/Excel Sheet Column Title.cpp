/**
	Excel Sheet Column Title
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string strReverse(string s)
    {
        string ans = "";
        for(int i = s.size()-1;i >= 0;i--)
            ans += s[i];
        return ans;
    }
    string convertToTitle(int n) {
        char int2char[26];
        int2char[0] = 'Z';
        for(int i = 1;i <= 25;i++)
            int2char[i] = 'A' + i - 1;
        string ans = "";
        if(n <= 26)
            return ans+int2char[n%26];
        while(n)
        {
            int tmp = n%26;
            ans += int2char[tmp];
            n /= 26;
            if(tmp == 0)
                n--;
        }
        return strReverse(ans);
    }
};

int main()
{
    Solution test;
    cout<<test.convertToTitle(78)<<endl;
}
