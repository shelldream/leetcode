/**
	Excel Sheet Column Number
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i = 0;i < s.size();i++)
        {
            int tmp = s[i] - 'A' + 1;
            ans = ans*26 + tmp;
        }
        return ans;
    }
};

int main()
{
    Solution test;
    cout<<test.titleToNumber("AB")<<endl;
}
