/**
	Power of Two
	Author:Xiaojun Huang
	Date:2015-08-10

*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        if(n == 1)
            return true;
        while(n)
        {
            if(n == 2)
                return true;
            if(n%2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};


int main()
{
    Solution solution;
    cout<<solution.isPowerOfTwo(128)<<endl;
}



