/*
	Combination Sum
	Author:Xiaojun Huang
	Date:2015-08-03

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return helper(candidates,target);
    }
    vector<vector<int> > helper(vector<int>& candidates, int target)
    {
        vector<vector<int> > ans;
        if(target<=0)
            return ans;
        for(int i=0;i < candidates.size();i++)
        {
            if(i==0 || (i-1>=0 && candidates[i] != candidates[i-1]))
                if(candidates[i] < target)
                {
                    vector<vector<int> > sub_result = helper(candidates, target-candidates[i]);
                    for(int m = 0;m < sub_result.size(); m++)
                    {
                        vector<int> tmp;
                        tmp.push_back(candidates[i]);
                        bool flag = true;
                        for(int n = 0;n < sub_result[m].size(); n++)
                        {
                            if(sub_result[m][n] >= candidates[i])
                                tmp.push_back(sub_result[m][n]);
                            else{
                                flag = false;
                                break;
                            }

                        }
                        if(flag)
                            ans.push_back(tmp);
                    }
                }
                else if(candidates[i] == target)
                {
                    vector<int> tmp;
                    tmp.push_back(candidates[i]);
                    ans.push_back(tmp);
                }
        }
        return ans;
    }
};

int main()
{
    int data[] = {2,2,2,2,3,6,7};
    int n = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+n);
	Solution solution;
	vector<vector<int> > ans = solution.combinationSum(nums,7);
	for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<"  ";
        cout<<endl;
    }

}

/*หตร๗


*/
