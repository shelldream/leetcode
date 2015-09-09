/**
	Roman to Integer
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <string>
using namespace std;

/**
�����ַ�
I
V
X
L
C
D
M
��Ӧ�İ��������ֱ�ʾΪ
1
5
10
50
100
500
1000

�������� ��X ��C �е��κ�һ�����������ù�����Ŀ�����߷��ڴ������ұ����ù�����Ŀ�������ܳ������������ڴ��������ֻ����һ����
���ܰѻ������� V ��L ��D �е��κ�һ����ΪС�����ڴ�������߲�������ķ���������Ŀ�����ڴ������ұ߲�����ӵķ�ʽ������Ŀ��ֻ��ʹ��һ����
V �� X ��ߵ�С����ֻ���� ��
L �� C ��ߵ�С����ֻ����X��
D �� M ��ߵ�С����ֻ���� C��

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
