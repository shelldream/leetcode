/**
	Number of Digit One
	Author:Xiaojun Huang
	Date:2015-09-11

*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    string int2str(unsigned long long n)
    {
        string s_n = "";
        while(n)
        {
            s_n += '0' + n%10;
            n /= 10;
        }
        string ans = "";
        for(int i = s_n.size()-1; i >= 0;i--)
        {
            ans += s_n[i];
        }
        return ans;
    }
    unsigned long long str2int(string s)
    {
        unsigned long long ans = 0;
        for(int i = 0;i < s.size();i++)
            ans = ans*10 + s[i] - '0';
        return ans;
    }
    int countDigitOne(int n) {
        if(n < 1)
            return 0;
        string strN = int2str(n);
        return countDigitOne(strN);
    }
    int countDigitOne(string strN)
    {
        if(strN.size() == 0)
            return 0;
        if(strN.size() == 1)
        {
            if(strN[0] == '0')
                return 0;
            else return 1;
        }
        else
        {
            int next_n = str2int(strN.substr(1,strN.size()-1));
            int count1 = countDigitOne(next_n);
            int count2 = 0;
            if(strN[0] == '1')
                count2 = str2int(strN.substr(1,strN.size()-1)) + 1;
            else count2 = pow(10, strN.size()-1);
            int first = strN[0] - '0';
            int count3 = first * (strN.size()-1) * pow(10,strN.size()-2);
            //cout<<count1<<"  "<<count2<<"  "<<count3<<endl;
            return count1+count2+count3;
        }
    }
};

int main()
{
    Solution test;
    cout<<test.countDigitOne(20)<<endl;  //12
    cout<<test.countDigitOne(100)<<endl;  //21
}
