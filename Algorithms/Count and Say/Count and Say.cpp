/**
	Count and Say
	Author:Xiaojun Huang
	Date:2015-09-10

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string iter_function(string pre_num)
    {
        string ans = "";
        char pre_bit = '*';
        int pre_cnt = 0;
        for(int i = 0;i < pre_num.size();i++)
        {
            char current_bit = pre_num[i];
            if(current_bit != pre_bit && pre_bit != '*')
            {
                ans += '0' + pre_cnt;
                ans += pre_bit;
                pre_bit = current_bit;
                pre_cnt = 1;
            }
            else
            {
                pre_bit = current_bit;
                pre_cnt++;
            }
        }
        ans += '0' + pre_cnt;
        ans += pre_bit;
        return ans;
    }
    string countAndSay(int n) {
        string m = "1";
        for(int i = 1;i <= n-1;i++)
        {
            m = iter_function(m);
        }
        return m;
    }
};

int main()
{
    Solution test;
    for(int i = 1;i <= 11;i++)
        cout<<test.countAndSay(i)<<endl;
}
