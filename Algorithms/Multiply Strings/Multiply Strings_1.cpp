/*
	Multiply Strings
	Author:Xiaojun Huang
	Date:2015-08-03
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverse_str(string str)
    {
        int i = 0;
        int j = str.size()-1;
        while(i < j)
        {
            char tmp = str[i];
            str[i++] = str[j];
            str[j--] = tmp;
        }
        return str;
    }

    string char_multi_str(string num,char c,int n) //某一位数乘以一个数
    {
        if(c == '0')
            return "0";
        string ans = "";
        for(int j = 0;j < n;j++)
            ans += "0";
        int x = c - '0';
        int carry_bit = 0;
        for(int i = num.size()-1;i >= 0;i--)
        {
            int y = num[i] - '0';
            int z = x*y;
            string str = "0";
            str[0] = z%10 + carry_bit + '0';
            str[1] = '\0';
            carry_bit = z/10;
            ans += str;
        }
        if(carry_bit)
        {
            string str = "0";
            str[0] = carry_bit + '0';
            str[1] = '\0';
            ans += str;
        }
        return reverse_str(ans);
    }
    string plus(string num1, string num2)
    {
        int carry_bit = 0;
        int k = 0;
        char num3[10000];
        int i = num1.size()-1;
        int j = num2.size()-1;
        while(i >=0 && j >= 0)
        {
            int x = num1[i--] - '0';
            int y = num2[j--] - '0';
            int z = x+y+carry_bit;
            num3[k++] = z%10+ '0';
            carry_bit = z/10;
        }
        while(i >=0)
        {
            int x = num1[i--] - '0' + carry_bit;
            carry_bit = x/10;
            num3[k++] = x%10 + '0';
        }
        while(j >= 0)
        {
            int y = num2[j--] - '0' + carry_bit;
            carry_bit = y/10;
            num3[k++] = y%10 + '0';
        }
        if(carry_bit)
            num3[k++] = '1';
        num3[k] = '\0';
        string ans = num3;
        return reverse_str(ans);
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string ans = "0";
        int j = 0;
        for(int i = num1.size()-1;i >= 0;i--)
        {
            string tmp = char_multi_str(num2,num1[i],j++);
            ans = plus(ans,tmp);
        }

        return ans;
    }
};

int main()
{
    string s1 = "140";
    string s2 = "0";
    //string s2 = "90000";
    Solution solution;
    //cout<<solution.plus("28840", "72100")<<endl;
    cout<<solution.multiply(s1,s2)<<endl;
}
