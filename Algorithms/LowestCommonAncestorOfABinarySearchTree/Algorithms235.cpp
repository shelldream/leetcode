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

        int x = p->val;
        int y = q->val;
        int min = x > y ? y : x;
        int max = x > y ? x : y;
        if (min <= root->val && max >= root->val)
            return root;
        else if (min > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (max < root->val)
            return lowestCommonAncestor(root->left, p, q);
        return NULL;
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
        TreeNode* p = new TreeNode(2);
        TreeNode* q = new TreeNode(8);
        TreeNode* res = solution.lowestCommonAncestor(root, p, q);
        if (res)
            cout << res->val << endl;
        else
            cout << "Cannot find common ancestor!" << endl;
        delete p;
        delete q;
    }

    {
        TreeNode* p = new TreeNode(0);
        TreeNode* q = new TreeNode(3);
        TreeNode* res = solution.lowestCommonAncestor(root, p, q);
        if (res)
            cout << res->val << endl;
        else
            cout << "Cannot find common ancestor!" << endl;
        delete p;
        delete q;
    }
}
