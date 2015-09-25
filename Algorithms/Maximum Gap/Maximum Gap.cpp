/**
	Permutations II
	Author:Xiaojun Huang
	Date:2015-09-24

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {

    }
};

int main()
{
	int data[] = {1,2,3,4,5};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    vector<vector<int> > ans = solution.permute(nums);
    for(int i = 0;i < ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }
}
