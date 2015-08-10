/**
	Unique Binary Search Trees II
	Author:Xiaojun Huang
	Date:2015-08-10

*/

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return construct_tree(1,n);
    }
    vector<TreeNode*> construct_tree(int i, int j)
    {
        vector<TreeNode*> ans;
        if(i > j)
            ans.push_back(NULL);
        else if(i == j)
        {
            TreeNode* root = new TreeNode(i);
            ans.push_back(root);
        }
        else
        {
            for(int k  = i;k <= j;k++)
            {
                vector<TreeNode*> left_subtrees = construct_tree(i, k-1);
                vector<TreeNode*> right_subtrees = construct_tree(k+1, j);
                for(int m = 0;m < left_subtrees.size();m++)
                    for(int n = 0;n < right_subtrees.size();n++)
                {
                    TreeNode* root = new TreeNode(k);
                    root->left = left_subtrees[m];
                    root->right = right_subtrees[n];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

void InOrderTraverse(TreeNode* root)
{
    if(root)
    {
        InOrderTraverse(root->left);
        cout<<root->val<<"  ";
        InOrderTraverse(root->right);
    }
}


int main()
{
    Solution solution;
    vector<TreeNode*> ans = solution.generateTrees(5);
    for(int i = 0; i < ans.size();i++)
    {
        InOrderTraverse(ans[i]);
        cout<<endl;
    }
}
