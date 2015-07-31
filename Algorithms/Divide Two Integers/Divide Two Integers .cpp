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
    int divide(int divid, int divi) {
        if (divi == 0)
            return INT_MAX;
        long long dividend = divid;
        long long divisor = divi;
        long long ans = 0;
        bool ans_postive_flag = true;
        if(dividend * divisor < 0)
            ans_postive_flag = false;
        if(dividend<0)
            dividend = -dividend;
        if(divisor<0)
            divisor = -divisor;
        while(dividend >= divisor)
        {
            long long tmp = divisor;
            long long tmp_count = 0;
            while(dividend >= tmp)
            {
                tmp = tmp<<1;
                tmp_count++;
                if(tmp<=0)
                    break;
            }
            ans += pow(2,tmp_count-1);
            if(tmp<=0)
                break;
            dividend -= tmp>>1;
        }
        if(ans_postive_flag)
            if (ans < INT_MAX)
                return ans;
            else return INT_MAX;
        else
            if (ans <= 2147483648)
                return -ans;
            else
                return INT_MAX;
    }
};

int main()
{
    Solution solution;
    cout<<solution.divide(100,0)<<endl;
    cout<<solution.divide(100,4)<<endl;
    cout<<solution.divide(100,-4)<<endl;
    cout<<solution.divide(10000000,1)<<endl;
    cout<<solution.divide(214743234243328364832, 1)<<endl;
    cout<<solution.divide(-2147483648, -2147483648)<<endl;
    cout<<solution.divide(-2147483648, 1)<<endl;
}

/*หตร๗


*/
