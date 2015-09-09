/**
	Add Binary
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int flag = 0;
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        while(i>=0 && j>=0)
        {
            int x,y;
            x = (a[i--] == '0')? 0:1;
            y = (b[j--] == '0')? 0:1;
            ans += '0' + (x+y+flag)%2;
            flag = (x+y+flag)/2;
        }
        while(i >= 0)
        {
            int x = (a[i--] == '0') ? 0:1;
            ans += '0' + (x+flag)%2;
            flag = (x+flag)/2;
        }
        while(j >= 0)
        {
            int y = (b[j--] == '0') ? 0 :1;
            ans += '0' + (y+flag)%2;
            flag = (y+flag)/2;
        }
        if(flag)
            ans += '0' + flag;
        int m = 0;
        int n = ans.size()-1;
        while(m < n)
        {
            char tmp = ans[m];
            ans[m++] = ans[n];
            ans[n--] = tmp;
        }
        return ans;
    }
};

int main()
{
    string a = "1111";
    string b = "10";
    Solution test;
    cout<<test.addBinary(a,b)<<endl;
}
