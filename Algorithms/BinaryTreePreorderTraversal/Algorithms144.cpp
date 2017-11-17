/*
    Description:
        Binary Tree Preorder Traversal
        https://leetcode.com/problems/binary-tree-preorder-traversal/description/
    Author: shelldream
    Date:2017-11-17
*/
#include <iostream>
#include <vector>
#include <stack>
#include "../../common/BinaryTree.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (NULL == root)
            return res;
        stack<TreeNode *> node_stack;
        TreeNode *p = root;
        while (p)
        {
            res.push_back(p->val);
            node_stack.push(p);
            p = p->left;
        }

        while (!node_stack.empty())
        {
            TreeNode *p = node_stack.top();
            node_stack.pop();
            if (p->right)
            {
                TreeNode *q = p->right;
                while (q)
                {
                    res.push_back(q->val);
                    node_stack.push(q);
                    q = q->left;
                }    
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
}

