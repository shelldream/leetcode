/*
	Search for a Range
	Author:Xiaojun Huang
	Date:2015-07-31
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int BinarySearch(vector<int>& nums, int s, int e, int target)
    {
        int low = s;
        int high = e;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int r_search_end(vector<int>& nums,int i,int j,int target)
    {
        if(j<i)
            return -1;
        int target_index = BinarySearch(nums,i,j,target);
        if(target_index == -1)
            return -1;
        else
        {
            if(target_index == j)
                return j;
            int right_end = r_search_end(nums,target_index+1,j,target);
            if(right_end == -1)
                return target_index;
            else return right_end;
        }
    }


    int l_search_end(vector<int>& nums,int i,int j,int target)
    {
        if(j<i)
            return -1;
        int target_index = BinarySearch(nums,i,j,target);
        if(target_index == -1)
            return -1;
        else
        {
            if(target_index == i)
                return i;
            int left_end = l_search_end(nums,i,target_index-1,target);
            if(left_end == -1)
                return target_index;
            else return left_end;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start_index = -1;
        int end_index = -1;
        int target_index = BinarySearch(nums,0,nums.size()-1,target);
        if(target_index != -1)
        {
            start_index = l_search_end(nums,0,target_index-1,target);
            end_index = r_search_end(nums,target_index+1,nums.size()-1,target);
            if(start_index == -1 && end_index != -1)
                start_index = target_index;
            else if(start_index != -1 && end_index == -1)
                end_index = target_index;
            else if(start_index == -1 && end_index == -1)
            {
                start_index = target_index;
                end_index = target_index;
            }
        }
        ans.push_back(start_index);
        ans.push_back(end_index);
        return ans;
    }
};

int main()
{
    //int data[] = {5, 7, 7, 8, 8, 8};
    int data[] = {1};
    int n = sizeof(data)/sizeof(data[0]);
    vector<int> nums(data,data+n);
    Solution solution;
    vector<int> ans = solution.searchRange(nums,1);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}

