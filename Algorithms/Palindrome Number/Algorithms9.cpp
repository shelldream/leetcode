/*
	Palindrome Number
	Author:Xiaojun Huang
	Date:2015-07-11
*/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        int bits_count = 0;
        int y = x;
        while(y)
        {
            bits_count++;
            y /=10;
        }
        int right_bit = 1;
        int left_bit = bits_count-1;
        while(left_bit>=right_bit)
        {
            int tail = x%int(pow(10,right_bit))/pow(10,right_bit-1);
            int head = x/int(pow(10,left_bit))%10;
            if(tail!=head)
                return false;
            left_bit--;
            right_bit++;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout<<solution.isPalindrome(22);

}

/*
备注：
1.不能用反转数的方法，可能会造成溢出
*/
