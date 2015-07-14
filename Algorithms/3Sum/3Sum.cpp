/*
	3Sum
	Author:Xiaojun Huang
	Date:2015-07-14

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int nums_size = nums.size();
        for(int k = 0;k < nums_size;k++)
        {
            if(k>0 && nums[k]==nums[k-1])//去重
                continue;
            int i = k+1;
            int j = nums_size-1;
            while(i < j)
            {
                int a = nums[i];
                int b = nums[j];
                int sum = a+b;
                if(sum == -nums[k])
                {
                    vector<int> tmp;
                    tmp.push_back(nums[k]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    ans.push_back(tmp);
                    while(i < j && nums[i] == a)i++;
                    while(i < j &&nums[j] == b) j--;
                }
                else if(sum>-nums[k])
                    while(i < j && nums[j] == b) j--;
                else
                    while(i < j && nums[i] == a)i++;
            }
        }
        return ans;
    }
};

int main()
{
	int data[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+size);
	Solution solution;
	vector<vector<int> > ans = solution.threeSum(nums);
	for(int i = 0;i < ans.size();i++)
	{
	    for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
	}
}

/*说明


*/
