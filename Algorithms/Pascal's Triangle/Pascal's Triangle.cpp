/**
	Pascal's Triangle
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        for(int i = 1; i <= numRows; i++)
        {
            vector<int> tmp;
            for(int j = 1;j <= i;j++)
            {
                if(j == 1 || j == i)
                    tmp.push_back(1);
                else
                {
                    tmp.push_back(ans[i-2][j-1] + ans[i-2][j-2]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main()
{
    Solution test;
    vector<vector<int> > ans = test.generate(10);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }
}
