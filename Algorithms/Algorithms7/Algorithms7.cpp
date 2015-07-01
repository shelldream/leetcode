/*
	Reverse Integer
	Author:Xiaojun Huang
	Date:2015-07-01
*/
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative_flag;
        long long ans=0;
        if(x<0)
        {
            negative_flag = true;
            x = -x;
        }
        else negative_flag = false;
        while(x)
        {
            ans = ans*10 + x%10;
            x /= 10;
        }
        if(negative_flag)
            ans = -ans;
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
        else
            return ans;
    }
};
int main()
{
    Solution solution;
    cout<<solution.reverse(1000)<<endl;
    cout<<solution.reverse(-1001)<<endl;
    cout<<solution.reverse(-12345678655453)<<endl;
    cout<<solution.reverse(1000000003)<<endl;
    cout<<solution.reverse(1003)<<endl;
}
