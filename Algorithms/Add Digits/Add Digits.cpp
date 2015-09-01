/**
	Add Digits
	Author:Xiaojun Huang
	Date:2015-09-01

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int tmp = 0;
            while(num)
            {
                tmp += num%10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};

int main()
{
    Solution solution;
    cout<<solution.addDigits(138)<<endl;
}
