/*
	Combinations
	Author:Xiaojun Huang
	Date:2015-07-27

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return helper(1, n ,k);
    }

    vector<vector<int> >helper(int start, int end, int num)
    {
        vector<vector<int> > ans;
        if(start > end || num==0)
            return ans;
        for(int i = start; i <= end-num+1; i++)
        {
            vector<vector<int> > next = helper(i+1, end, num-1);
            if(next.size() == 0)
            {
                vector<int> tmp;
                tmp.push_back(i);
                ans.push_back(tmp);
            }
            for(int j = 0; j < next.size(); j++)
            {
                vector<int> tmp;
                tmp.push_back(i);
                for(int k = 0;k < next[j].size(); k++)
                    tmp.push_back(next[j][k]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;

    vector<vector<int> > ans = solution.combine(4,2);
    //vector<vector<int> > ans = solution.helper(1,1,1);
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

/*หตร๗


*/
