/**
	Ugly Number II
	Author:Xiaojun Huang
	Date:2015-08-21

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 6)
            return n;
        vector<long long> ugly_nums;
        for(int i = 1;i <= 6;i++)
            ugly_nums.push_back(i);
        while(ugly_nums.size() < n)
        {
            int nums_size = ugly_nums.size();
            long long max_val = ugly_nums[nums_size - 1];
            long long m2 = max_val;
            long long m3 = max_val;
            long long m5 = max_val;
            for(int j = nums_size-1;j >= 0;j--)
                if(ugly_nums[j]*2 <= max_val)
                {
                    m2 = ugly_nums[j+1]*2;
                    break;
                }
            for(int j = nums_size-1;j >= 0;j--)
                if(ugly_nums[j]*3 <= max_val)
                {
                    m3 = ugly_nums[j+1]*3;
                    break;
                }
            for(int j = nums_size-1;j >= 0;j--)
                if(ugly_nums[j]*5 <= max_val)
                {
                    m5 = ugly_nums[j+1]*5;
                    break;
                }
            cout<<m2<<"  "<<m3<<"   "<<m5<<endl;
            ugly_nums.push_back(min(min(m2,m3),m5));
        }
        return ugly_nums[n-1];
    }
};

int main()
{
    Solution solution;
    cout<<solution.nthUglyNumber(1407)<<endl;
}
