/**
	Merge Sorted Array
	Author:Xiaojun Huang
	Date:2015-09-09

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(i >= 0)
            nums1[k--] = nums1[i--];
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    int data1[] = {1,3,5,7,9,0,0,0,0,0};
    int n1 = sizeof(data1)/sizeof(data1[0]);
    vector<int> nums1(data1,data1+n1);
    int data2[] = {0,2,4,6,8};
    int n2 = sizeof(data2)/sizeof(data2[0]);
    vector<int> nums2(data2,data2+n2);
    Solution test;
    test.merge(nums1, 5, nums2, 5);
    for(int i = 0;i < nums1.size();i++)
        cout<<nums1[i]<<"  ";
}
