/*
	Description:
        String to Integer (atoi)
	    https://leetcode.com/problems/string-to-integer-atoi/description/
    Author: shelldream
	Date:2017-10-29
*/
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool negative_flag = false;
        int i = 0;
        int len = str.length();
        long long ans = 0;
        while(str[i] == ' ')
            i++;
        if(str[i]=='-')
        {
            negative_flag = true;
            i++;
        }
        else if(str[i] == '+')
            i++;
        while(i < len)
        {
            if(str[i]>='0' && str[i]<='9')
                ans = ans*10 + (str[i++] - '0');
            else if (str[i] == '+' || str[i] == '-')
                return 0;
            else
                break;
            if (!negative_flag && ans > INT_MAX)
                return INT_MAX;
            if(negative_flag && -ans < INT_MIN)
                return INT_MIN;
        }
        if(negative_flag)
            return -ans;
        else return ans;
    }
};

int main()
{
    Solution solution;
    cout<<solution.myAtoi("-1000")<<endl;
    cout<<solution.myAtoi("    010")<<endl;//10
    cout<<solution.myAtoi("+-2")<<endl;//0
    cout<<solution.myAtoi("  -0012a42")<<endl;//-12
    cout<<solution.myAtoi("9223372036854775809")<<endl;
    cout<<solution.myAtoi("2147483648")<<endl;//2147483647
    cout<<solution.myAtoi("-2147483648")<<endl;//-2147483648
}


