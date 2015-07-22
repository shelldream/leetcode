/*
	4Sum
	Author:Xiaojun Huang
	Date:2015-07-22

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int vector_size = nums.size();
        for(int i = 0;i < vector_size; i++)
        {
            while(i-1 >=0 && nums[i]==nums[i-1]) i++;
            int three_sum_target = target - nums[i];
            for(int j = i+1;j < vector_size;j++)
            {
                while (j-1 >=i+1 && nums[j]==nums[j-1]) j++;
                int two_sum_target = three_sum_target-nums[j];
                int low = j+1;
                int high = vector_size-1;
                while(low < high)
                {
                    while(low < high && low-1 >= j+1 && nums[low] == nums[low-1]) low++;
                    while(low < high && high+1 <= vector_size-1 && nums[high] == nums[high+1]) high--;
                    if(low >= high)
                        break;
                    if(nums[low] + nums[high] == two_sum_target)
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[low]);
                        tmp.push_back(nums[high]);
                        ans.push_back(tmp);
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < two_sum_target)
                        low++;
                    else
                        high--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int data[] = {-1,2,2,-5,0,-1,4};
	int size = sizeof(data)/sizeof(data[0]);
	vector<int> nums(data,data+size);
	Solution solution;
	vector<vector<int> > ans = solution.fourSum(nums,3);
	for(int i = 0;i < ans.size();i++)
	{
	    for(int j = 0;j < ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
	}
}

/*
หตร๗


*/
