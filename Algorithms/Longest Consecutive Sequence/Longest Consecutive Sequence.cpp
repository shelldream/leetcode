/**
	Longest Consecutive Sequence
	Author:Xiaojun Huang
	Date:2015-08-11

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        map<int,int> num_count;
        for(int i = 0;i < nums.size();i++)
            if(num_count.count(nums[i]) == 0)
                num_count[nums[i]] = 1;
        for(int i = 0;i< nums.size();i++)
        {
            if(num_count.count(nums[i]))
            {
                int tmp_count = 1;
                int tmp = nums[i]+1;
                while(num_count.count(tmp) != 0)
                {
                    tmp_count++;
                    num_count.erase(tmp);
                    tmp++;
                }
                tmp = nums[i]-1;
                while(num_count.count(tmp) != 0)
                {
                    tmp_count++;
                    num_count.erase(tmp);
                    tmp--;
                }
                num_count.erase(nums[i]);
                if(tmp_count > ans)
                    ans = tmp_count;
            }
        }
        return ans;
    }
};

int main()
{
    int data[] = {2,3,1,1,4};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    cout<<solution.longestConsecutive(nums)<<endl;

}



