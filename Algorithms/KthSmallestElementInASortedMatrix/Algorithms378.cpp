/**
 *  Description:Kth Smallest Element in a Sorted Matrix https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 *  Author:Xiaojun Huang
 *  Date:2016-08-05
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while (left < right)
        {
            int mid = (left+right) >> 1;
            int num = 0;
            for (size_t i = 0; i < n; ++i)
            {
                int upper_index = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin(); //找到第一个比mid大的元素下标
                num += upper_index;
            }
            if (num >= k)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        
        }
        return right;
    }
};


int main()
{
    const int N = 3;
    int data[N][N] = {{1,5,9}, {10,11,13}, {12,13,15}};
    vector<vector<int> > matrix;
    
    for (size_t i = 0; i < N; ++i)
    {
        vector<int> tmp;
        for (size_t j = 0; j < N; ++j)
        {
            tmp.push_back(data[i][j]);
        }
        matrix.push_back(tmp);
    }
    Solution solution;
    cout<<solution.kthSmallest(matrix, 8)<<endl;
}
