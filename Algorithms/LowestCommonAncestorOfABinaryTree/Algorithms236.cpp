/*
    Description: 
         Lowest Common Ancestor of a Binary Search Tree
         https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
    Author: shelldream
    Date: 2017-10-29
*/

#include <iostream>
#include <vector>
#include "../../common/BinaryTree.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root || NULL == p || NULL == q)
            return NULL;
        if (p == root || q == root)
            return root;
            
        TreeNode* left = lowestCommonAncestor(root->left, p, q);        
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        else return left != NULL ? left : right;
    }
};


int main()
{
    Solution solution;
    int predata[] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
    int indata[] = {6, 2, 0, 4, 3, 5, 8, 7, 9};
    vector<int> preorder(predata, predata+sizeof(predata)/sizeof(int));
    vector<int> inorder(indata, indata+sizeof(indata)/sizeof(int));
    TreeNode* root = buildTreePreIn(preorder, inorder);
    
    {
        TreeNode* res = solution.lowestCommonAncestor(root, root, root);
        if (res)
            cout << res->val << endl;
        else
            cout << "Cannot find common ancestor!" << endl;
    }

}
