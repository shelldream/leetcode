/**
	Reverse Bits
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 1;
        uint32_t ans = 0;
        while(i)
        {
            ans += n&1;
            i <<= 1;
            if(i)
                ans <<= 1;
            n >>= 1;
        }
        return ans;
    }
};

int main()
{
    Solution test;
    cout<<test.reverseBits(43261596)<<endl;
}
