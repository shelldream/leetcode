/**
	Ugly Number
	Author:Xiaojun Huang
	Date:2015-08-21

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        while(num > 1)
        {
            if(num%2 == 0)
                num /= 2;
            else if(num%3 == 0)
                num /= 3;
            else if(num%5 == 0)
                num /= 5;
            else return false;
        }
        if(num == 1)
            return true;
        else return false;
    }
};

int main()
{
    Solution solution;
    cout<<solution.isUgly(35)<<endl;
}
