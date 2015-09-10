/**
	Valid Palindrome
	Author:Xiaojun Huang
	Date:2015-09-10

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char c)
    {
        if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
            return true;
        else return false;
    }
    char lower(char c)
    {
        if(c >= 'A' && c <= 'Z')
            return 'a' + c - 'A';
        else return c;
    }
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            while(i < j && !isAlphaNum(s[i])) i++;
            while(i < j && !isAlphaNum(s[j])) j--;
            if(lower(s[i]) != lower(s[j]))
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};

int main()
{
    Solution test;
    string s1 = "1A man, a plan, a canal: Panama2";
    string s2 = "race a car";
    cout<<test.isPalindrome(s1)<<endl;
    cout<<test.isPalindrome(s2)<<endl;
}
