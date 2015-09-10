/**
	Pascal's Triangle II
	Author:Xiaojun Huang
	Date:2015-09-10

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex, 0);
        for(int i = 1;i <= rowIndex;i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(j == 0 || j== i-1)
                {
                    ans[j] = 1;
                }
                else
                {
                    int tmp = 0;
                    for(int k = 0;k <= j-1;k++)
                        tmp = ans[k]-tmp;
                    ans[j] += tmp;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution test;
    for(int j = 1;j <= 10;j++)
    {
        vector<int> ans = test.getRow(j);
        for(int i = 0;i < ans.size();i++)
            cout<<ans[i]<<"  ";
        cout<<endl;
    }
}
