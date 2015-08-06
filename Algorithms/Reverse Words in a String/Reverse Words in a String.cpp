/**
	Reverse Words in a String
	Author:Xiaojun Huang
	Date:2015-08-06
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverse_str(string& s,int i, int j)
    {
        if(j <= i)
            return;
        int start_index = i;
        int end_index = j;
        while(start_index <= end_index)
        {
            char tmp = s[start_index];
            s[start_index++] = s[end_index];
            s[end_index--] = tmp;
        }
    }
    void reverseWords(string &s) {
        reverse_str(s, 0, s.size()-1);
        int i = 0;
        while(i < s.size())
        {
            int j = i;
            while(j < s.size())
            {
                if(s[j] != ' ')
                    j++;
                else break;
            }
            reverse_str(s,i,j-1);
            i = j+1;
        }
        postprocess(s);
    }
    void postprocess(string &s)
    {
        int i = 0;
        while(i < s.size()) /** 除去连续的空格*/
        {
            while(s[i] == ' ' && s[i+1] == ' ')
            {
                move_char_in_str(s, i);
            }
            i++;
        }
        if(s[0] == ' ')
            move_char_in_str(s,0);
        int k = s.size()-1;
        if(s[k] == ' ')
        {
            s[k] = '\0';
            s = s.substr(0,k);
        }
    }
    void move_char_in_str(string& s, int start)
    {
        int k = s.size()-1;
        while(start <= k)
        {
            s[start] = s[start+1];
            start++;
        }
        s = s.substr(0,k);
    }
};
int main()
{
    Solution solution;
    //string test = "       the                 sky                is            blue hahaha               ";
    //string test = "                          ";
    //string test = "     1";
    string test = "a";
    cout<<test.size()<<endl;
    solution.reverseWords(test);
    cout<<test<<endl;
    cout<<test.size()<<endl;
}

/**
1.连续空格情况，连续空格合并成一个空格
2.不能以空格开头或结尾

排坑指南：
每次移动完string对象以后要用substr重新构造一下，不然size()返回的值有错
*/
