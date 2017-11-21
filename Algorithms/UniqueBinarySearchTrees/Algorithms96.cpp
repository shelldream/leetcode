/*
    Description:
        Unique Binary Search Trees
        https://leetcode.com/problems/unique-binary-search-trees/description/
    Author: shelldream
    Date:2017-11-21
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (0 == n)
            return 1;

        vector<int> tree_num(n+1, 0);
        tree_num[0] = 1;
        tree_num[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                tree_num[i] += tree_num[j]*tree_num[i-j-1];
            }
        }
        return tree_num[n];
    }
};


int main()
{
    Solution solution;
    cout << solution.numTrees(1) << endl;
    cout << solution.numTrees(2) << endl;
    cout << solution.numTrees(3) << endl;
}

