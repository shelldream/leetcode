/*
    Description:
        Binary Tree Inorder Traversal
        https://leetcode.com/problems/binary-tree-inorder-traversal/description/    
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> node_stack;
        if (NULL == root)
            return res;
        TreeNode *p = root;
        while (p)
        {
            node_stack.push(p);
            p = p->left;
        }

        while (!node_stack.empty())
        {
            TreeNode *top = node_stack.top();
            res.push_back(top->val);
            node_stack.pop();
            if (top->right != NULL)
            {
                TreeNode *q = top->right;
                
                while (q)
                {
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
    int predata[] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
    int indata[] = {6, 2, 0, 4, 3, 5, 8, 7, 9};
    vector<int> preorder(predata, predata+sizeof(predata)/sizeof(int));
    vector<int> inorder(indata, indata+sizeof(indata)/sizeof(int));
    TreeNode* root = buildTreePreIn(preorder, inorder);
    vector<int> res = solution.inorderTraversal(root);
    for (size_t i = 0; i < res.size(); ++i)
    {
        cout << res[i] << "  ";
    }
    cout << endl;
}

