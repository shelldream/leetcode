/*
	Search a 2D Matrix
	Author:Xiaojun Huang
	Date:2015-08-05
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        vector<int> head_element;
        for(int i = 0;i < matrix.size();i++)
            head_element.push_back(matrix[i][0]);
        int index = Binary_Search_head(head_element,target);
        if (index < 0)
            return false;
        return Binary_Search(matrix[index],target);
    }
    bool Binary_Search(vector<int> nums,int target)
    {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    int Binary_Search_head(vector<int> nums, int target)
    {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid+1;
            else high = mid-1;
        }
        return high;
    }
};

int main()
{
    int data[4][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,50},{70,100,342,23232}};
    vector<vector<int> > matrix;
    for(int i = 0;i < 4;i++)
    {
        vector<int> tmp;
        for(int j = 0;j < 4;j++)
            tmp.push_back(data[i][j]);
        matrix.push_back(tmp);
    }
    Solution solution;
    cout<<solution.searchMatrix(matrix,1234560)<<endl;
}

