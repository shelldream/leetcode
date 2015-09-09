/**
	Plus One
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int flag = 1;
        for(int i = digits.size()-1;i >= 0;i--)
        {
            int current_digit = digits[i] + flag;
            ans.push_back(current_digit%10);
            flag = current_digit/10;
        }
        if(flag)
            ans.push_back(flag);
        int i = 0;
        int j = ans.size()-1;
        while(i < j)
        {
            int tmp = ans[i];
            ans[i++] = ans[j];
            ans[j--] = tmp;
        }
        return ans;
    }
};

int main()
{
    int data[] = {9,9,9,9,8};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution test;
    for(int i = 0;i < nums.size();i++)
        cout<<nums[i]<<"  ";
    cout<<endl;
    vector<int> ans = test.plusOne(nums);
    for(int i = 0;i < ans.size();i++)
        cout<<ans[i]<<"  ";
    cout<<endl;
}
