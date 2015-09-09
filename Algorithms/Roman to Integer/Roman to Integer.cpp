/**
	Roman to Integer
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

/**
基本字符
I
V
X
L
C
D
M
相应的阿拉伯数字表示为
1
5
10
50
100
500
1000

基本数字 Ⅰ、X 、C 中的任何一个、自身连用构成数目、或者放在大数的右边连用构成数目、都不能超过三个；放在大数的左边只能用一个；
不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目、只能使用一个；
V 和 X 左边的小数字只能用 Ⅰ；
L 和 C 左边的小数字只能用X；
D 和 M 左边的小数字只能用 C。

*/


class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0;i < s.size();i++)
        {
            switch(s[i])
            {
                case 'I': ans += 1;break;
                case 'V':
                    {
                        ans += 5;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'I')
                                ans -= 2;
                            else break;
                        }
                        break;
                    }
                case 'X':
                    {
                        ans += 10;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'I')
                                ans -= 2;
                            else break;
                        }
                        break;
                    }
                case 'L':
                    {
                        ans += 50;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'X')
                                ans -= 20;
                            else break;
                        }
                        break;
                    }
                case 'C':
                    {
                        ans += 100;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'X')
                                ans -= 20;
                            else break;
                        }
                        break;
                    }
                case 'D':
                    {
                        ans += 500;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'C')
                                ans -= 200;
                            else break;
                        }
                        break;
                    }
                case 'M':
                    {
                        ans += 1000;
                        int j = i-1;
                        while(j >= 0 && j >= i-3)
                        {
                            if(s[j--] == 'C')
                                ans -= 200;
                            else break;
                        }
                        break;
                    }

            }
        }
        return ans;
    }
};

int main()
{
    Solution test;
    //string s = "MDCCCLXXXVIII";
    string s = "MCMXCVI";
    cout<<test.romanToInt(s)<<endl;
}
