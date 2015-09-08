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
    string int2str(long long x)
    {
        if(x == 0)
            return "0";
        string ans = "";
        if(x < 0)
        {
            ans += "-";
            x = -x;
        }
        vector<char> tmp;
        while(x)
        {
            tmp.push_back('0' + x%10);
            x /= 10;
        }
        for(int i = tmp.size()-1; i >=0;i--)
            ans += tmp[i];
        return ans;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        long long start = nums[0];
        long long end = nums[0];
        for(int i = 0;i < nums.size();i++)
        {
            if(i+1 < nums.size() && (nums[i+1]-nums[i] == 1))
            {
                end = nums[i+1];
            }
            else
            {
                string tmp = "";
                tmp += int2str(start);
                if(start == end)
                    ans.push_back(tmp);
                else
                {
                    tmp += "->";
                    tmp += int2str(end);
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
    int data[] = {0,1,2,4,5,7};
    //int data[] = {-2147483648,-2147483647,2147483647};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    vector<string> ans = test.summaryRanges(nums);
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<endl;
}
