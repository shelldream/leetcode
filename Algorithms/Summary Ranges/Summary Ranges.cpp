/**
	Summary Ranges
	Author:Xiaojun Huang
	Date:2015-09-08

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        int start = nums[0];
        int end = nums[0];
        for(int i = 0;i < nums.size();i++)
        {
            if(i+1 < nums.size() && (nums[i+1]-nums[i] == 1))
            {
                end = nums[i+1];
            }
            else
            {
                string tmp = "";
                tmp += ('0' + start);
                if(start == end)
                    ans.push_back(tmp);
                else
                {
                    tmp += "->";
                    tmp += ('0' + end);
                    ans.push_back(tmp);
                }
                if(i+1 < nums.size())
                {
                    start = nums[i+1];
                    end = start;
                }
            }
        }
        return ans;
    }
};


int main()
{
    //int data[] = {0,1,2,4,5,7};
    int data[] = {0,3};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    vector<string> ans = test.summaryRanges(nums);
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<endl;
}
