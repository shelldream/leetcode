/**
	Remove Duplicates from Sorted Array II
	Author:Xiaojun Huang
	Date:2015-08-21

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int times_count = 1;
        int ans = 0;
        int j = 1;
        while(j < n)
        {
            if(nums[j] == nums[ans])
            {
                times_count++;
                if(times_count <= 2)
                {
                    ans++;
                    nums[ans] = nums[j];
                    j++;
                }
                else
                {
                    while(nums[j] == nums[ans])
                        j++;
                }
            }
            else
            {
                nums[++ans] = nums[j++];
                times_count = 1;
            }
        }
        return ans+1;
    }
};

int main()
{
    Solution solution;
    int data[] = {1,1,1,1,1,2,2,3,4,5,5,5,6};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> test(data,data+n);
    int ans = solution.removeDuplicates(test);
    cout<<ans<<endl;
    for(int i = 0;i < ans;i++)
        cout<<test[i]<<"  ";
    cout<<endl;
}
