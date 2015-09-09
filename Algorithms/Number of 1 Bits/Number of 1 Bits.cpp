/**
	Number of 1 Bits
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ham_cnt = 0;
        while(n)
        {
            ham_cnt++;
            n = n&(n-1);
        }
        return ham_cnt;
    }
};

int main()
{
    Solution test;
    uint32_t n = 11;
    cout<<test.hammingWeight(n)<<endl;
}
