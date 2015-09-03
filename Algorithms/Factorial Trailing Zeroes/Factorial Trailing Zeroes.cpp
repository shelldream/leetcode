/**
	Factorial Trailing Zeroes
	Author:Xiaojun Huang
	Date:2015-09-03

*/

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n)
        {
            ans += n/5;
            n /= 5;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout<<solution.trailingZeroes(10);
}
