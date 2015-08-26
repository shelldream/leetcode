/*
	Divide Two Integers
	Author:Xiaojun Huang
	Date:2015-07-31

*/

#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(divisor == 0)
            return INT_MAX;
        bool isPositive;
        if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            isPositive = true;
        else isPositive = false;
        long long l_dividend = (dividend > 0) ? dividend : -dividend;
        long long l_divisor = (divisor > 0) ? divisor : -divisor;
        long long ans = 0;
        while(l_dividend >= l_divisor)
        {
            long long tmp = l_divisor;
            long long tmp_ans = 1;
            while(tmp <= l_dividend)
            {
                tmp_ans = tmp_ans<<1;
                tmp = tmp<<1;
            }
            l_dividend -= tmp>>1;
            ans += tmp_ans>>1;
        }
        ans = isPositive ? ans : -ans;
        if(ans >= INT_MAX)
            return INT_MAX;
        else if(ans <= INT_MIN)
            return INT_MIN;
        else return ans;
    }
};
int main()
{
    Solution solution;
    //cout<<solution.divide(100,0)<<endl;
    //cout<<solution.divide(100,4)<<endl;
    //cout<<solution.divide(100,-4)<<endl;
    //cout<<solution.divide(10000000,1)<<endl;
    cout<<solution.divide(-1010369383, -2147483648)<<endl;
    //cout<<solution.divide(-2147483648, -2147483648)<<endl;
    //cout<<solution.divide(-2147483648, 1)<<endl;
}

/*หตร๗


*/
