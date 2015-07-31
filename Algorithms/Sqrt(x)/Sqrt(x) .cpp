/*
	Sqrt(x)
	Author:Xiaojun Huang
	Date:2015-07-31

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        unsigned long long low = 0;
        unsigned long long high = x;
        while(low <= high)
        {
            unsigned long long mid = (low+high)/2;
            if(mid*mid == x)
                return mid;
            else if(mid*mid < x)
                low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};
int main()
{
    Solution solution;
    cout<<solution.mySqrt(2147395599);
    //for(int i = 0;i <= 10000;i++)
    //    cout<<i<<"   "<<solution.mySqrt(i)<<endl;
}

/*说明

x值如果过大，注意越界问题
数据要定义为 unsigned long long 类型

*/
