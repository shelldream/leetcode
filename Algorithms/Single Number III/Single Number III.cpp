/**
	Single Number III
	Author:Xiaojun Huang
	Date:2015-09-23

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num1,num2,result_OR;
        result_OR = nums[0];
        for(int i = 1;i < nums.size();i++)
            result_OR ^= nums[i];

        int mask = 1;
        while((mask & result_OR) == 0)
            mask = mask<<1;
        num1 = 0;
        num2 = 0;
        for(int i = 0;i < nums.size();i++){
            if((nums[i] & mask) == 0){
                num1 ^= nums[i];
            }
            else
                num2 ^= nums[i];
        }
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};

int main()
{

	//int data[] = {1,2,3,4,2,1,3,4,6,5,7,7,8,9,8,9};
    int data[] = {1193730082,587035181,-814709193,1676831308,-511259610,284593787,-2058511940,1970250135,-814709193,-1435587299,1308886332,-1435587299,1676831308,1403943960,-421534159,-528369977,-2058511940,1636287980,-1874234027,197290672,1976318504,-511259610,1308886332,336663447,1636287980,197290672,1970250135,1976318504,959128864,284593787,-528369977,-1874234027,587035181,-421534159,-786223891,933046536,959112204,336663447,933046536,959112204,1193730082,-786223891};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
	Solution test;
	vector<int> ans = test.singleNumber(nums);
	cout<<ans[0]<<"  "<<ans[1]<<endl;
}
