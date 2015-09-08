/**
	First Bad Version
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
using namespace std;

bool isBadVersion(int version)
{
    if(version >= 10)
        return true;
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long long i = 1;
        long long j = n;
        while(i < j)
        {
            long long mid = (i+j)/2;
            if(!isBadVersion(mid))
                i = mid+1;
            else
            {
                if(!isBadVersion(mid-1))
                    return mid;
                else j = mid-1;
            }
        }
    }
};


int main()
{
    Solution test;
    cout<<test.firstBadVersion(9)<<endl;
}
