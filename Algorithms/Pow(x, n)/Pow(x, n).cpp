/**
	Pow(x, n)
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0)
            return 1.0;
        if(n < 0)
            return 1/myPow(x, -n);
        double half = myPow(x,n/2);
        half = (half>0) ? half:-half;
        if(half <= 0.0000000000001)
            return 0.0;
        if((n & 1) == 0)
            return half*half;
        else return half*half*x;
    }
};
int main()
{
	Solution test;
    cout<<test.myPow(-13.62608, 3)<<endl;
}
