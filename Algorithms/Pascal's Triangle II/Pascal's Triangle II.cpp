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
        vector<int> ans(rowIndex+1, 0);
        for(int i = 0;i <= rowIndex;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                if(j == 0 || j== i)
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
    vector<int> ans = test.getRow(4);
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<"  ";
    cout<<endl;
}
